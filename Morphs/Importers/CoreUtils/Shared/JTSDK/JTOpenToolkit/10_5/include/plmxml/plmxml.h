//////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/*! \mainpage
 *
 * \section intro Introduction
<p></p>
<p>This manual contains a complete reference to the PLM XML SDK API. It contains documentation 
   for every interface (classes, methods, error codes, and so on) in the PLM XML SDK.</p>
<p>You can navigate the PLM XML SDK API Reference using the menu immediately above. </p>
<p></p>
 */

//////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_H__
#define __PLMXML_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64) || defined(PLMXML_DECLSPEC)
#ifdef PLMXML_EXPORTS
#define PLMXML_API __declspec(dllexport)
#else
#define PLMXML_API __declspec(dllimport)
#endif
#else
#define PLMXML_API
#endif

#include <memory.h>

#if defined(__linux__) || ( defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x5140) || ( defined(__APPLE_CC__) && ! ( defined(__ppc__) || defined(__ppc64__) ) )
#include <new>
#else
#include <new.h>
#endif

#define PLMXML_BEGIN_NAMESPACE( ns ) namespace ns {
#define PLMXML_END_NAMESPACE  }
#define PLMXML_USE_NAMESPACE( ns ) using namespace ns;

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#if defined(_WIN32) || defined(_WIN64)
#define PLMXML_SHLIB_HANDLE		                HINSTANCE
#define PLMXML_SHLIB_PROC( handle, procname )	GetProcAddress(handle, procname)
#define PLMXML_SHLIB_LOAD( name )				LoadLibrary(name)
#define PLMXML_SHLIB_UNLOAD( name )				FreeLibrary(name)
#else
#define PLMXML_SHLIB_HANDLE		                void*
#define PLMXML_SHLIB_PROC( handle, procname )	dlsym(handle, procname)
#if defined __APPLE__
#define PLMXML_SHLIB_LOAD( name )	            dlopen((const char*)(plmxml_api::String("lib")+plmxml_api::String(name)+plmxml_api::String(".dylib")), RTLD_LAZY)
#elif !defined(__hpux) || (defined(__hpux) && defined(__ia64))
#define PLMXML_SHLIB_LOAD( name )	            dlopen((const char*)(plmxml_api::String("lib")+plmxml_api::String(name)+plmxml_api::String(".so")), RTLD_LAZY)
#else 
#define PLMXML_SHLIB_LOAD( name )	            dlopen((const char*)(plmxml_api::String("lib")+plmxml_api::String(name)+plmxml_api::String(".sl")), RTLD_LAZY)
#endif
#define PLMXML_SHLIB_UNLOAD( name )				dlclose(name)
#endif

//////////////////////////////////////////////////////////////////////

PLMXML_BEGIN_NAMESPACE( plmxml_api )

//////////////////////////////////////////////////////////////////////
class BuildInfoData;
//! Build information class.
/*!
    Instance of this class can be requested from a component.
    It provides access to component version information as well as
    build date and time.
    \sa GetBuildInfo()
*/
class PLMXML_API BuildInfo
{
    BuildInfoData* m_Data;

public:

    //! Default constructor.
    BuildInfo();

    //! Constructor used by components.
	/*!
		@param major	Major version number.
		@param minor	Minor version number.
		@param revision	Revision number.
		@param build	Build number.
		@param year		Build year.
		@param month	Build month.
		@param day		Build day.
		@param hour		Build hour.
		@param minute	Build minute.
		@param second	Build second.
	*/
    BuildInfo( int major, int minor, int revision, int build, int year, int month, int day, int hour, int minute, int second );

    //! Constructor used by components.
	/*!
		@param	major		Major version number.
		@param	minor		Minor version number.
		@param	revision	Revision number.
		@param	build		Build number.
		@param	datetime	Date time information about the build as a String. The string should be formatted
							in the following way:
							\verbatim
								dd/mm/yyyy HH:mm:ss
							\endverbatim
	*/
    BuildInfo( int major, int minor, int revision, int build, const char* datetime );

    //! Copy constructor
	/*!
		@param	bi		BuildInfo object to initialise this instance from.
	*/
    BuildInfo( const BuildInfo& bi );

    //! Assignment operator
	/*!
		@param	bi		Sets the value of an existing BuildInfo instance to that of a specified BuildInfo instance.
		@return			The updated BuildInfo instance.
	*/
    const BuildInfo& operator=( const BuildInfo& bi );

    //! Destructor.
    virtual ~BuildInfo();

    //! Get major version number.
	/*!
		@return		The major version.
	*/
    int GetMajorRevision() const;

    //! Get minor version number.
	/*!
		@return		The minor version.
	*/
    int GetMinorRevision() const;

    //! Get revision number.
	/*!
		@return		The revision.
	*/
    int GetRevision() const;

    //! Get build number.
	/*!
		@return		The build number.
	*/
    int GetBuildNumber() const;

    //! Get build year.
	/*!
		@return		The build year.
	*/
    int GetYear() const;

	//! Get build month.
	/*!
		@return		The build month.
	*/
	int GetMonth() const;

	//! Get build day.
	/*!
		@return		The build day.
	*/
    int GetDay() const;

	//! Get build hour.
	/*!
		@return		The build hour.
	*/
	int GetHour() const;

	//! Get build minute.
	/*!
		@return		The build minute.
	*/
    int GetMinute() const;

	//! Get build second.
	/*!
		@return		The build second.
	*/
	int GetSecond() const;
};

#define PLMXML_BUILD_INFO( name_export ) \
    name_export plmxml_api::BuildInfo GetBuildInfo( void );

#define PLMXML_BUILD_INFO_OBJECT                        \
	plmxml_api::BuildInfo( VERSION_INFO_MAJOR,          \
                    VERSION_INFO_MINOR,                 \
                    VERSION_INFO_REVISION,              \
                    VERSION_INFO_BUILDNUMBER,           \
                    VERSION_INFO_DATE )                 \

#define PLMXML_BUILD_INFO_RETURN                        \
    {                                                   \
	    return PLMXML_BUILD_INFO_OBJECT;                \
    }

#define PLMXML_BUILD_INFO_IDENT                         \
    char* ___rev = "$Revision: " VERSION_INFO_IDENT_STRING " $";

#define PLMXML_BUILD_INFO_IMPL                          \
    PLMXML_BUILD_INFO_IDENT                             \
    plmxml_api::BuildInfo GetBuildInfo( void )          \
    {                                                   \
        PLMXML_BUILD_INFO_RETURN                        \
    }

//////////////////////////////////////////////////////////////////////

//! Logical type (TRUE or FALSE)
typedef int logical;

//! Unicode character type.
typedef unsigned short UChar;

//////////////////////////////////////////////////////////////////////
//! Modeller handle type. Used to store pointers to representation specific data.
typedef void* PLMXML_MODELLER_HANDLE;

//! Null modeller handle.
#define PLMXML_MODELLER_HANDLE_NULL NULL

////////////////////////////////////////////////////////////////////////////
// fields can be Required, Optional, or have defaults

//! plmxmlRequired Required field
#define plmxmlRequired     NULL
//! plmxmlOptional Optional field
#define plmxmlOptional     ((char *) -1)

#define plmxmlContent      Content

//! Field selection modes - Attribute field
#define PLMXML_FIELD_ATTRIBUTE  (1<<1)
//! Field selection modes - Element field
#define PLMXML_FIELD_ELEMENT    (1<<2)
//! Field selection modes - Content field
#define PLMXML_FIELD_CONTENT	(1<<3)
//! Field selection modes - Any field
#define PLMXML_FIELD_ANY        PLMXML_FIELD_ELEMENT|PLMXML_FIELD_ATTRIBUTE|PLMXML_FIELD_CONTENT

class Object;
class FieldDescriptor;
class Transf;
class UnitVector;

//////////////////////////////////////////////////////////////////////
// forward declarations
class AllocatorBase;
class DeAllocatorBase;

//////////////////////////////////////////////////////////////////////
//! Memory Allocator class
/*!
	Memory handling class used throughout the various plmxml toolkits.
	The default implementation is to use malloc and free for allocation
	and deallocation. 
	This implementation can be overridden by defining custom allocation
	routines by deriving classes from AllocatorBase and DeAllocatorBase
	and registering them with Allocator::RegisterHandlers - to restore 
	the default	implementation register NULL and NULL as the handlers.

	For example:

    \code
	// define derived classes from AllocatorBase and DeAllocatorBase
	// overloading the operator '( )'
	class  MyAllocator : public AllocatorBase
	{
	public:
		virtual void* operator( ) ( size_t size )
		{
			return malloc( size );
		}
	};

	class MyDeAllocator : public DeAllocatorBase
	{
	public:
		virtual void operator( ) ( void* pointer )
		{
			free( pointer );
		}
	};
	
	// Instantiate instances of the custom memory handlers
    // as static variables

	static MyAllocator		m_alloc;
	static MyDeAllocator	m_dealloc;

	// register these two handlers with the system
	Allocator::RegisterHandlers( m_alloc, m_dealloc );

	//... Perform some operation

	// restore the original memory handling behaviour
	Allocator::RegisterHandlers( NULL, NULL );

    \endcode

	NOTE: 
	
	 On IBM Aix-32 platforms the Allocator class is not 
	used throughout the toolkits for memory managment - the 
	toolkits instead uses the default implementation of new
	and delete. 

*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API Allocator
{

private:

	static DeAllocatorBase*		pDeAllocatorBase;
	static AllocatorBase*		pAllocatorBase;

public:

	//! Allocate memory
	static void*	allocate( size_t size );
	
	//! Deallocate memory
	static void		deallocate( void* pointer );

	//! Copy memory
	static void		copy( void* dest, const void* src, size_t count );

	//! Compare memory
	static int		compare( const void* buf1, const void* buf2, size_t count );

    //! Set memory
    static void     set( void* dest, int c, size_t count );

    //! Move memory
    static void     move( void* dest, const void* src, size_t count );

    //! Register custom memory handlers
	static void RegisterHandlers( AllocatorBase* pAlloc, DeAllocatorBase* pDealloc );

	//! Get the registered allocator function or NULL if none registered.
	static AllocatorBase* GetAllocator( );

	//! Get the registered deallocator function or NULL if none registered.
	static DeAllocatorBase* GetDeAllocator( );

#ifndef PLMXML_DEFAULT_ALLOCATORS

	//! Overloaded new operator
	static void*	operator new( size_t size );

	//! Overloaded delete operator
	static void		operator delete( void* pointer );

	//! Overloaded new (array) operator
	static void*	operator new[]( size_t size );

	//! Overloaded delete (array) operator
	static void		operator delete[]( void* pointer );

#endif

};

//////////////////////////////////////////////////////////////////////
//! Custom Allocator base class
/*!
	To define you own Custom Allocators derive classes from AllocatorBase
	and DeAllocatorBase, override the '( )' operator and register 
	in the Allocator::RegisterHandlers function
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API AllocatorBase
{
public:
    //! This function is called for every memory allocation using operator 'new'.
	virtual void* operator( ) ( size_t size ) = 0; 
};

//////////////////////////////////////////////////////////////////////
//! Custom DeAllocator base class
/*!
	To define you own Custom Allocators derive classes from AllocatorBase
	and DeAllocatorBase, override the '( )' operator and register 
	in the Allocator::RegisterHandlers function
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API DeAllocatorBase
{
public:
    //! This function is called for every memory deallocation using operator 'delete'.
	virtual void operator( ) ( void* pointer ) = 0; 
};

//////////////////////////////////////////////////////////////////////
//! Variable length array class.
/*!
    Template class.
    Instantiations should only include arrays of 'simple' objects,
    i.e. objects without any virtual functions as well as 
    primitive types. These 'simple' classes must implement operator==
    for the linear search function Array::Lookup.
*/
//////////////////////////////////////////////////////////////////////

template <class T>
class Array
{
protected:

    //! Storage buffer.
    T*     m_Data;
    //! Length of the array.
    unsigned int    m_Size;
    //! Allocated length of the array, length of the buffer.
    unsigned int    m_Maxsize;

private:
    void Copy( const Array<T>& a )
    {
		RemoveAll( );
		Add( a.GetSize( ), a.GetData( ) );
    }

public:

    //! Virtual destructor. 
	/*! 
		Will be called by destructors of derived classes.
	*/
    virtual ~Array( )
    {
		RemoveAll( );
        if( m_Data )
			Allocator::deallocate( m_Data );
    }
    //! Default constructor. 
	/*! 
		Does not allocate any storage.
	*/
    Array( )
	: m_Data( 0 ), m_Size( 0 ), m_Maxsize( 0 )
	{
    }
    //! Copy constructor. 
	/*!
		Allocates new buffer to the length of the source array.

		@param	a	The existing Array to initialise this Array instance from.
	*/
    Array( const Array<T>& a )
	: m_Data( 0 ), m_Size( 0 ), m_Maxsize( 0 )
	{
		Add( a.GetSize( ), a.GetData( ) );
    }
    //! Constructors a new Array instance from an existing source buffer.
	/*!
		@param	length		The length of the buffer 'a'
		@param	a			The source buffer. The contents of this buffer are copied into
							this Array instance.
	*/
    Array( int length, const T* a )
	: m_Size( 0 ), m_Maxsize( 0 ), m_Data( 0 )
	{
		Add( length, a );
    }
	//! Constructs a new Array instance with the specified storage capacity.
	/*!
		@param	length		The length to initially set the storage capacity of this to.
	*/
	Array( int length )
	: m_Data( 0 ), m_Size( 0 ), m_Maxsize( 0 )
	{

		SetSizeEx( length, FALSE );
		m_Size = 0;
	}
    //! Assignment operator. 
	/*!
		@param	a	The source array to set the contents of this array to.
		@returns	Updated array.
    */
	const Array<T>& operator=( const Array<T>& a )
    {
		RemoveAll( );
		Add( a.GetSize( ), a.GetData( ) );

        return (*this);
    }
    //! Append an element to the end of the array.
	/*!
		@param	val		Append a new element to the end of the array.
		@returns		The new size of the array.
	*/
    virtual int Add( const T& val )
    {
        SetSize( m_Size+1 );
        SetAt( m_Size-1, val );

        return m_Size;
    }
    //! Append an array of elements to the end of the array.
	/*!
		@param	length	Number of elements to append to the end of the array.
		@param	a		Array of elements to add.
		@returns		Size of the array after the elements have been added.
	*/
    virtual int Add( int length, const T* a )
    {
		// filter invalid arguments
		if ( length <= 0 || !a )
			return m_Size;

		int	initialSize	= m_Size;
        SetSize( m_Size+length );

		int nCopy = ( length > 3) ? 3 : length;

        for( int k = initialSize; k < nCopy + initialSize; k++ )
			SetAt( k, a[ k - initialSize ] );

		int nLeft = length - nCopy;
		if ( !nLeft )	// already copied everything
			return m_Size;

        if( !Allocator::compare( &m_Data[ initialSize ], &a[ 0 ], nCopy * sizeof( T ) ) )
	        Allocator::copy( &m_Data[ initialSize + nCopy ], &a[ nCopy ], nLeft * sizeof( T ) );
        else
        {
            for( int i = nCopy; i < length; i++ )
                SetAt( i, a[ i ] );
        }

        return m_Size;
    }
    //! Get the length of the array.
    /*!
		@returns	The size of the array.
	*/
	int GetSize() const
    {
        return m_Size;
    }
    //! Get a pointer to the allocated buffer for read-only operations. 
	/*!
		@returns	Pointer to allocated internal buffer. THIS MUST NOT BE DELETED.
    */
	T* GetData( void ) const 
    { 
        return m_Data; 
    }
    //! Change the length of the array.
    /*! 
        @param	n	New size of the array. 
		
		Allocated size remains the same if new length is less than current, trailing buffer is 
        set to NULL.
        
        If new length is greater than allocated length, new buffer is created, contents copied
        and old buffer deleted.
    */
    void SetSize( int n )
    {
        SetSizeEx( n, TRUE );
    }
	//!	Changes the length of the array.
	/*!	
		@param	n			New size of the array.
		@param	extendMax	Whether to extend the size of the array past 'n' for performance reasons.
	*/
    void SetSizeEx( int n, logical extendMax )
    {
        // if invalid request
        if ( n < 0 )
            return;

        unsigned int un = n;

        // if same size
        if( un == m_Size )
            return;

        // if new size is less than current
        if( un < m_Size )
        {
            m_Size = un;
            return;
        }

        // if new size is greater than current but less than allocated size
        if( un <= m_Maxsize )
        {
            m_Size = un;
            return;
        }

        // allocate new storage and nullify it
        // copy existing data into the new storage
        // delete the old storage

        // keep double length max_size if length is more than one
        unsigned int newsize = m_Maxsize = (un==1 || !extendMax) ? un : un*2;

		T* newdata = (T*)Allocator::allocate( sizeof( T ) * newsize );
        Allocator::set( newdata, 0, newsize*sizeof(T) );

        if( m_Data )
            Allocator::copy( newdata, m_Data, m_Size*sizeof(T) );

        Allocator::set( m_Data, 0, m_Size*sizeof(T) );

        m_Size = un;
        T* tmpdata = m_Data;
        m_Data = newdata;

        if( tmpdata )
			Allocator::deallocate( tmpdata );
    }

	//@{
	//! Provides read-only access to an element at a specific index.
	/*!
		@param	i	Index of the element in the array to return. The index must be in within
					the bounds of the array.
		@returns	A reference to the element at the specified index in the array.
	*/
    virtual const T& GetAt( int i ) const
    {
        return m_Data[i];
    }
    virtual const T& operator[]( int i ) const
    {
        return GetAt(i);
    }
	//@}
		
	//! Sets the value of a specified element in the array.
	/*!
		@param	i		Index of the element in the array to set. The index must be in within
						the bounds of the array.
		@param	val		New value of element to set.
	*/
    virtual void SetAt( int i, const T& val )
    {
		new( m_Data + i ) T( val );
    }

	//! Provides access to an element at a specific index.
	/*!
		@param	i	Index of the element in the array to return. The index must be in within
					the bounds of the array.
		@returns	A reference to the element at the specified index in the array.
	*/
    virtual T& operator[]( int i )
    {
        return m_Data[i];
    }

    //! Insert new element into the array, extending the size by one.
	/*!
		@param	i		The index at which to add an element. The index must be within the bounds
						of the array.
		@param	val		The new element to insert into the array.
	*/
    void InsertAt( int i, const T& val )
    {
        if ( i < 0 )
            return;

        unsigned int ui = i;

        if( ui==m_Size )
        {
            SetSize( m_Size+1 );
            SetAt( m_Size-1, val );
            return;
        }

        if( ui> m_Size )
            return;

        SetSize( m_Size+1 );
        Allocator::move( &m_Data[ui+1], &m_Data[ui], (m_Size-ui-1)*sizeof(T) );
        Allocator::set( &m_Data[ui], 0, sizeof(T) );
        m_Data[ui] = val;
    }

    //! Reverse the array.
    void Reverse()
    {
		if ( m_Size <= 1 )
			return;

		T	temp;
		for ( unsigned int i = 0, j = m_Size-1; i < m_Size/2; i++, j-- )
		{
			temp		= m_Data[i];
			m_Data[i]	= m_Data[j];
			m_Data[j]	= temp;
		}
    }

    //! Remove an element from the array, reducing its size by one.
	/*!
		@param	i	Index of element to remove from the array. The index must be within the bounds
					of the array.
	*/
    void RemoveAt( int i )
    {
        if ( i < 0 )
            return;

        unsigned int ui = i;

        if( ui>=m_Size )
            return;

		m_Data[ ui ].~T( );
        Allocator::move( &m_Data[ui], &m_Data[ui+1], (m_Size-ui-1)*sizeof(T) );
		Allocator::set( &m_Data[m_Size-1], 0, sizeof(T) );
        m_Size--;
    }

    //! Remove all elements from the array, the buffer and maximum size are not changed.
    void RemoveAll()
    {
        for( unsigned int i = 0; i < m_Size; i++ )
            m_Data[ i ].~T();
		Allocator::set( m_Data, 0, m_Size*sizeof(T) );
        m_Size = 0;
    }

    //! Find an element in the array. 
	/*!
		@param		val		The value to lookup in the array.
		@returns			The index of the matched element or -1 if element is not contained in the array. 
    */
	int Lookup( const T& val ) const
    {
        for( int i=0; i<GetSize(); i++ )
            if( val == m_Data[i] )
                return i;

        return -1;
    }
};

//////////////////////////////////////////////////////////////////////
class StringImpl;

//! String Encoding.
/*!
	Defines a series of different text encoding that is used to specify data
	for a String.
*/
typedef int EncodingType;

//@{ \name Encoding types
//! Unicode (UTF-16) encoding. Each character is represented as a 'UChar'.
const EncodingType	EncodingTypeUTF16		= 0;
//! ANSI encoding. Each encoded character is represented as a 'char'.
const EncodingType	EncodingTypeANSI		= 1;
//! UTF-8 encoding. Each character is represented as a 'char'.
const EncodingType	EncodingTypeUTF8		= 2;
//@}

//! Unicode String class
/*!
    Represents a Unicode (UTF-16) encoded String based on the UChar data type.
	<p>
	A String object can be initialised from the following types:

	\verbatim
			String			An existing String instance.
			UChar			A single UChar character repreated one or more times.
			UChar*			A UChar character string.
			char*			An ANSI character string. This must not be encoded in any form other than ANSI
							(for example UTF-8). To set a String instance from an UTF-8 encoded string use 
							the functions that take a void* and an encoding type.
			void*			A buffer that can either be a UChar* string, ANSI character string or UTF-8 
							encoded string depending on the value of the supplied encoding parameter.
	\endverbatim		
	\note
	The buffer can not be shared between instances.
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API String
{
protected:

	//! Internal data.
	StringImpl*		m_pImpl;

	//! Friend class.
	friend class StringImpl;

public:

    //! Constructs a new empty instance of the String class.
    String();

    //! Constructs a String based on an existing String instance.
	/*!
		@param	s	An existing String to be copied into this String.
	*/
    String( const String& s );

    //! Constructs a String from the supplied ANSI character array.
	/*!
		@param	src	A pointer to a NULL terminated ANSI string array to be copied into this String.
	*/
	String( const char *src );

    //! Construct a String from supplied Unicode character array
	/*!
		@param	src	A pointer to a NULL terminated Unicode (UTF-16) string array to be copied into this String.
	*/
    String( const UChar* src );

	//! Construct a String from a single Unicode character repeated a specified number of times.
	/*!
		@param	c	The single character to construct the String from.
		@param	n	The number of times 'c' should occur.

		@throws		ErrorCodeInvalidArgument	If 'n' is < 0
	*/
    String( UChar c, int n = 1 );

    //! Construct a String from supplied Unicode character array.
	/*!
		@param	src	A pointer to a NULL terminated Unicode (UTF-16) string array to be copied into this String.
		@param	n	The length of the unicode array not including any terminating NULL character.

		@throws		ErrorCodeInvalidArgument	if 'n' < 0
	*/
	String( const UChar* src, int n );

    //! Construct a String from supplied ANSI character array.
	/*!
		@param	src	A pointer to a NULL terminated ANSI string array to be copied into this String.
		@param	n	The length of the ANSI array not including any terminating NULL character.

		@throws		ErrorCodeInvalidArgument	if 'n' < 0
	*/
    String( const char* src, int n );

	//! Construct a String from a supplied source Array and a character encoding.
	/*!
		@param	src			A pointer to a source array to be copied into this String. The type of data in
							this array will depend on the value of 'encoding'.
		@param	n			The number of characters in the source array.
		@param	encoding	Specifies how the source array 'src' is encoded.

		@throws		ErrorCodeInvalidIndex		if 'n' < 0.
		@throws		ErrorCodeInvalidArgument	if the specified 'encoding' is invalid.
		@throws		ErrorCodeInvalidEncoding	if the encoding of 'src' is incorrect.			
	*/
	String( const void* src, int n, EncodingType encoding );

	//! Destructor.
    ~String();

    //@{ \name Assignment operators

	//! Sets the contents of an existing String to the value of the supplied String.
	/*!
		@param	s	The String to set this String to.
		@return			The updated String.
	*/
    String& operator=( const String& s );

	//! Sets the contents of an existing String to the value of the supplied Unicode (UTF-16) array.
	/*!
		@param	src		A pointer to a NULL terminated Unicode (UTF-16) string array to set this String to.
		@return				The updated String.
	*/
	String& operator=( const UChar* src );

	//! Sets the contents of an existing String to the value of the supplied ANSI array.
	/*!
		@param	src		A pointer to a NULL terminated ANSI string array to set this String to.
		@return				The updated String.
	*/
	String& operator=( const char* src );
    //@}

	//! Set this String to a Unicode (UTF-16) string.
	/*!
		@param	src		A pointer to a NULL terminated Unicode (UTF-16) string array to be copied into this String.
		@param	length	The length of the unicode array not including any terminating NULL character.
		@return				<code>TRUE</code> if operation succeeded - <code>FALSE</code> otherwise.
	*/
	logical Set( const UChar* src, int length );

	//! Set this String to ANSI string.
	/*!
		@param	src		A pointer to a NULL terminated ANSI string array to be copied into this String.
		@param	length	The length of the ANSI array not including any terminating NULL character.
		@return			<code>TRUE</code> if operation succeeded - <code>FALSE</code> otherwise.
	*/
	logical Set( const char* src, int length );

	//! Set the value of this String from a supplied source Array and a character encoding.
	/*!
		@param	src			A pointer to a source array to be copied into this String. The type of data in
							this array will depend on the value of 'encoding'.
		@param	length		The number of characters in the source array.
		@param	encoding	Specifies how the source array 'src' is encoded.
		@return				<code>TRUE</code> if operation succeeded - <code>FALSE</code> otherwise.
	*/
	logical Set( const void* src, int length, EncodingType encoding );

	//! Set this String to UTF-8 encoded string.
	/*!
		@param	src		A pointer to a NULL terminated UTF-8 encoded string array to be copied into this String.
		@param	length	The length of the array not including any terminating NULL character.
		@return			<code>TRUE</code> on success - <code>FALSE</code> otherwise.

		@throws	ErrorCodeInvalidArgument	if 'n' < 0
	*/
	logical SetUTF8( const char* src, int length );

	//! Set this String to UTF-8 encoded string.
	/*!
		@param	src		A pointer to a NULL terminated UTF-8 encoded string array to be copied into this String.
		@return				<code>TRUE</code> on success - <code>FALSE</code> otherwise.
	*/
	logical SetUTF8( const char* src );

	//! Removes the contents of the String and sets the length to be 0.
	void Empty( );

	//! Determines whether the string is empty
	/*!
		@returns	<code>TRUE</code> if the String is empty - <code>FALSE</code> otherwise.
	*/
	logical IsEmpty( ) const;

	//@{ \name Concatenation operators
    //! Concatenation, append a String to this string.
	/*!
		@param	s	The String to append to this String.
		@return		The concatenated String.
	*/
    String& operator+=( const String& s );
	
	//! Append a single Unicode character to this String.
	/*!
		@param	c	The Unicode character to append.
		@return			The concatenated String.
	*/
	String& operator+=( UChar c );
        
	//! Append an ANSI string to this String.
	/*!
		@param	src	A pointer to a NULL terminated ANSI string array to be appended to this String.
		@return		The concatenated String.
	*/
	String& operator+=( const char* src );
	//@}

    //! Determines whether two specified String objects have the same value.
	/*!
		@param	s1	A String.
		@param	s2	A String.
		@return		<code>TRUE</code> if the value of the Strings is equal <code>FALSE</code> otherwise.
	*/
	friend logical PLMXML_API operator==( const String& s1, const String& s2 );

    //! Determines whether a String and an ANSI string have the same value.
	/*!
		@param	s1	A String.
		@param	s2	A NULL terminated ANSI string array.
		@return		<code>TRUE</code> if the value of 's1' is equal to 's2' <code>FALSE</code> otherwise.
	*/
	friend logical PLMXML_API operator==( const String& s1, const char* s2 );

    //! Determines whether an ANSI string and a String have the same value.
	/*!
		@param	s1	A NULL terminated ANSI string array.
		@param	s2	A String.
		@return		<code>TRUE</code> if the value of 's1' is equal to 's2' <code>FALSE</code> otherwise.
	*/
	friend logical PLMXML_API operator==( const char* s1, const String& s2 );

    //! Determines whether two specified String objects have different values.
	/*!
		@param	s1	A String.
		@param	s2	A String.
		@return		<code>TRUE</code> if the value of the Strings are not equal <CODE>FALSE</CODE> otherwise.
	*/
	friend logical PLMXML_API operator!=( const String& s1, const String& s2 );

    //! Determines whether two specified String objects have different values.
	/*!
		@param	s1	A String.
		@param	s2	A NULL terminated ANSI string array.
		@return		<code>TRUE</code> if the value of 's1' is not equal to 's2' <code>FALSE</code> otherwise.
	*/
    friend logical PLMXML_API operator!=( const String& s1, const char* s2 );

    //! Concatenates two Strings.
	/*!
		@param	s1	The first String.
		@param	s2	The second String.
		@return		A String representing the concatenation of 's1' and 's2'.
	*/
    friend String PLMXML_API operator+( const String& s1, const String& s2 );

    //! Concatenates a String and an ANSI string.
	/*!
		@param	s1	A String.
		@param	s2	An NULL terminated ANSI string array.
		@return		A String representing the concatenation of 's1' and 's2'.
	*/
    friend String PLMXML_API operator+( const String& s1, const char* s2 );

    //! Concatenates an ANSI string and a String.
	/*!
		@param	s1	An NULL terminated ANSI string array.
		@param	s2	A String.
		@return		A String representing the concatenation of 's1' and 's2'.
	*/
    friend String PLMXML_API operator+( const char* s1, const String& s2 );

    //! Compare two Strings.
	/*!
		@param	s1	The first String.
		@param	s2	The second String.
		@return			<code>TRUE</code> if the value of 's1' is less than the value of 's2' - <code>FALSE</code> otherwise.
	*/
    friend logical PLMXML_API operator<( const String& s1, const String& s2 );

    //! Get the length of the String.
	/*!
		@return		The length of the String not including any terminating NULL character.
	*/
    int GetLength() const;
    
    //! Returns a pointer to the internal character buffer for the String.
	/*!
		@return		The String buffer. This must not be modified in any way.
					For an empty String this may be either "" or NULL.
	*/
    UChar* GetData( void ) const;

	//! Get UTF8 representation.
	/*!
		@param	result	The resultant UTF-8 encoded String.
	*/
	void GetUTF8String( String& result ) const;
	
	//! Get a UTF-8 encoded representation of the String.
	/*!
		@return		The resultant UTF-8 encoded String.
		@deprecated	Replaced by the more efficient plmxml_api::String::GetUTF8String( String& result ) const.
	*/
    String GetUTF8String( void ) const;

	//! Get a UTF-8 encoded representation escaped for XML.
	/*!
		@param	result	The resultant UTF-8 encoded String escaped for XML. 

		The UTF-8 encoded representation has &lt; escaped by '&lt', &amp; as '&amp;', 
		and &quot; as '&quot;'
	*/
	void GetUTF8XMLString( String &result ) const;

    //! Get a UTF8 representation escaped for XML.
	/*!
		@return		The resultant UTF-8 encoded String escaped for XML.
		@deprecated	Replaced by the more efficient plmxml_api::String::GetUTF8XMLString( String& result ) const.
	*/
    String GetUTF8XMLString( void ) const;
  
	//! Get the String as an UTF-8 encoded string.
	/*!
		@return		The String encoded as a UTF-8 string. This must not be 
					modified in any way. For an empty string this may be either
					"" or NULL.
					To check if a String is empty need to call #IsEmpty
	*/
	operator const char*() const;

	//! Returns a pointer to the internal character buffer for the String.
	/*!
		@return		The String buffer. This must not be modified in any way.
					For an empty String this may be either "" or NULL.
					To check if a String is empty need to call #IsEmpty
	*/
	operator const UChar*() const;

    //! Read-only access to a Unicode character within the String.
	/*!
		@param	i	The index of the Unicode character to return.
		@return		The Unicode character in the String at index 'i'.
	*/
    const UChar& operator[]( int i ) const;

    //! Write access to a Unicode character within the String.
	/*!
		@param	i	The index of the Unicode character to return.
		@return		The Unicode character in the String at index 'i'.
	*/
    UChar& operator[]( int i );

	//! Returns the index of the first occurrence of the specified String.
	/*!
		@param	subString	The String to seek within this String.
		@return				The index in this String that 'subString' was found at, or -1 
							if not found. If 'subString' is empty then the return value is 0.
	*/
	int Find( const String& subString ) const;

	//! Returns the index of the last occurrence of the specified String.
	/*!
		@param	subString	The String to seek within this String.
		@return				The index in this String of the that the last instance of 'subString' was 
							found at, or -1 if not found. If 'subString' is empty then the return value is 0.
	*/
	int FindLast( const String& subString ) const;

	//! Replace all instances of the specified Unicode character within this String with another Unicode character.
	/*!
		@param	cOld	The Unicode character in the String to replace.
		@param	cNew	A Unicode character to replace all instances of 'cOld'
		@return			The number of instances of 'cOld' that were replaced in this String.
	*/
	int Replace( UChar cOld, UChar cNew );

	//! Replace all instances of the specified String within this String with another String.
	/*!
		@param	oldString		The String to replace.
		@param	newString		A String to replace all instances of 'oldString'.
		@return					The number of instances of 'oldString' that were replaced.
	*/
	int Replace( const String& oldString, const String& newString );

	//! Replace all instances of the specified String within this String with an ANSI string.
	/*!
		@param	oldString		The String to replace.
		@param	newString		A NULL terminated ANSI string to replace all instances of 'oldString'.
		@return						The number of instances of 'oldString' that were replaced.
	*/
	int Replace( const char* oldString, const char* newString );

	//! Finds the last token, using given separators.
	/*!
		Regards the string as a sequence of tokens separated by any of the
		separating characters, and returns the last token. 
	
		@param		separators	A list of separators to be used to split the String. For example:
								<code>";/|"</code>
		@return		The last token. If the string ends in a separator, returns "". 
					If there are no separators in the string, returns the entire string.
	*/
	String GetLastToken( const String& separators ) const;
	
    //! Splits the string into array of Strings according to a deliminator.
	/*!
		@param	separators	A String containing the Unicode characters that will be used to 
								deliminate substrings within this String.
		@param	result		An Array containing any substrings of this String that were deliminated 
								by characters in 'separators'. The array will be empty if the String is not
								split according to 'separators'.
	*/
    void Split( const String& separators, Array<String>& result ) const;

	//! Retrieves a substring of this string.
	/*!
		@param		startIndex			The index of the start of the substring.
		@return								A String representing a substring of this String starting at 'startIndex'
											and finishing at the end of the String.
		@throws		ErrorCodeInvalidIndex	If 'startIndex' is less than 0 or greater than the length of this
											String.
	*/
	String Substring( int startIndex ) const;

	//!	Retrieves a substring of this string. 
	/*!  The substring starts at the specified character position and has the specified length.
		@param	startIndex	The index of the start of the substring.
		@param	length		The length of the substring.

		@throws	ErrorCodeInvalidIndex	If startIndex + length is larger then the string, or
		either startIndex or length < 0.
	*/
	String Substring( int startIndex, int length ) const;

	//! Determines whether the start of this string matches a specified String.
	/*!
		@param	value	The String to check.
		@return				<code>TRUE</code> if this String starts with 'value' or <code>FALSE</code> otherwise.
	*/
	logical StartsWith( const String& value ) const;

	//! Determines whether the end of this string matches a specified String.
	/*!
		@param	value	The String to check.
		@return				<code>TRUE</code> if this String end with 'value' or <code>FALSE</code> otherwise.
	*/
	logical EndsWith( const String& value ) const;

	//! Compares this string to another string.
	/*!
		@param	value	The String to compare this String to.
		@return				<code>0</code>	if the string is equal to 'value'
							<code>&lt; 0</code> if the string is less than 'value'
							<code>&gt; 0</code> if the string is greater than 'value'
	*/
	int Compare( const String& value ) const;

	//! Compares this string to an ANSI string.
	/*!
		@param	value	The NULL terminated ANSI string to compare this String to.
		@return				<code>0</code>	if the string is equal to 'value'
							<code>&lt; 0</code> if the string is less than 'value'
							<code>&gt; 0</code> if the string is greater than 'value'
	*/
	int Compare( const char* value ) const;

    //! Make a lower case string.
	/*!
		@return		A lowercase version of this String.
	*/
    String LowerCase( void ) const;

    //! Make upper case string.
	/*!
		@return		An uppercase version of this String.
	*/
    String UpperCase( void ) const;

    //! Writes formatted data to a new String.
	/*	The formatted data is in the same form as that used for sprintf in C.
		@param	format	The NULL terminated ANSI string used to format the data.
		@return				A String formatted according to 'format'.
	*/
    static String Format( const char* format, ... );

	//! Returns an empty string.
	/*
		@return		An empty String.
	*/
	static const String& EmptyString( );
};

////////////////////////////////////////////////////////////////////////////
//! Handle class
/*!
    Stores any representation specific data and associated format
    including pointers to plmxml_api::Object*, in this case format is "PLMXML"
*/
class PLMXML_API Handle
{
	//! Internal data
    PLMXML_MODELLER_HANDLE	m_Data;

	//! Internal data
	String					m_Format;

public:

    //! Default constructor.
    Handle();

    //! Constructors a Handle from an existing Object.
	/*!
		@param	o	Object pointer to store in this Handle. The format will be set to "PLMXML".
	*/
    Handle( Object* o );

    //! Constructor, sets the type to format.
	/*!
		@param	h			Data to store in this Handle instance.
		@param	format		Format of the data stored in the Handle.
	*/
    Handle( PLMXML_MODELLER_HANDLE h, const String& format );

	//! Copy constructor.
	/*!
		@param	info	Instance of a Handle to contruc this instance from.
	*/
	Handle( const Handle& info );

	//! Assignment operator.
	/*!
		@param	info	Instance of a Handle to set the value of this instance to.
	*/
	Handle& operator=( const Handle& info );

    //! Compare two PLMXML Handles.
	/*!
		@param	h1		The first Handle instance to compare.
		@param	h2		The second Handle instance to compare.
		@returns	<code>TRUE</code>
	*/
    friend logical PLMXML_API operator==( const Handle& h1, const Handle& h2 );

    //! Compare two PLMXML Handles
    friend logical PLMXML_API operator<( const Handle& h1, const Handle& h2 );

    //! Get the format of the handle
    const String& GetFormat() const;

    //! Set the format of the handle
    void SetFormat( const String& format );

    //! Check if the handle is of "PLMXML" format 
    logical IsObject() const;

    //! Check if the handle is of "PLMXML" format and cast to plmxml::Object*
    Object* operator->() const;

    //! Check if the handle is of "PLMXML" format and cast to plmxml::Object*
    operator Object*() const;

    //! Cast to PLMXML_MODELLER_HANDLE
    operator PLMXML_MODELLER_HANDLE() const;

    //! Cast operator
    operator long() const;

    //! Cast operator
    operator int() const;

	//! Returns the stored Object* (if this is a Handle to an Object*) otherwise NULL
	Object* GetObject( ) const;

	//! Returns the stored data.
	PLMXML_MODELLER_HANDLE GetData( ) const;

    //! Reset the handle contents, does not destroy data
    void Clear();

    //! Destroy the handle, free format's data using corresponding data adapter.
    void Destroy();
};

///////////////////////////////////////////////////////////////////

class ReferenceImpl;

//! Reference class
/*!
	Storage class for information relating to reference attributes. 
*/
class PLMXML_API Reference
{
	//! Internal
	ReferenceImpl*	m_pImpl;

	friend class ReferenceImpl;
	
public:

	//! Constructs an empty Reference
	Reference( );

	//! Copy constructor
	Reference( const Reference& info );

	//! Constructs a Reference from the supplied Handle
	Reference( const Handle& refHandle );

	//! Constructs a Reference from the supplied handles
	Reference( const Array<Handle>& refHandles );

	//! Constructs a Reference from the supplied String
	Reference( const String& refString );

	//! Constructs a Reference from the supplied String and Handle
	Reference( const String& refString, const Handle& refHandle );

	//! Constructs a Reference from the supplied String and Handles
	Reference( const String& refString, const Array<Handle>& refHandles );

	//! Destructor
	~Reference( );

	//! Assignment operator
	Reference& operator=( const Reference& info );

	//! Returns the stored String
	const String& GetString( ) const;

	//! Sets the string associated with the reference
	void SetString( const String& refString );

	//! Returns the first stored Handle
	const Handle& GetHandle( ) const;

	//! Returns the stored handles
	const Array<Handle>& GetHandles( ) const;

	//! Compare two PLMXML References
    friend logical PLMXML_API operator==( const Reference& r1, const Reference& r2 );

    //! Compare two PLMXML References
    friend logical PLMXML_API operator<( const Reference& r1, const Reference& r2 );
};

////////////////////////////////////////////////////////////////////////////////////
// Special cases for Class enumeration

//! plmxmlClass definition. 
/*! Every class in PLMXML toolkit has associated plmxmlClass.
    eg. plmxml::ViewControl has plmxmlClassViewControl.
    plmxmlClass values are automatically assigned at run-time
    and must not be changed by the application.
*/
typedef short plmxmlClass;

const plmxmlClass plmxmlClassUnset             = -999;
const plmxmlClass plmxmlClassNull              = 0;

const plmxmlClass plmxmlClassInteger		   = -21;
const plmxmlClass plmxmlClassDouble			   = -22;
const plmxmlClass plmxmlClassString			   = -23;
const plmxmlClass plmxmlClassLogical		   = -24;
const plmxmlClass plmxmlClassGenericObject	   = -25;

//////////////////////////////////////////////////////////////////////////////////
//! plmxmlFieldType enum. Field Type enumeration.
/*!
    Values include:

    \verbatim
    plmxmlFieldUnset			
    plmxmlFieldLogical			
    plmxmlFieldInt				
    plmxmlFieldDouble			
    plmxmlFieldString			
    plmxmlFieldSingleReference	
    plmxmlFieldMultipleReference
    plmxmlFieldSingleElement	
    plmxmlFieldMultipleElement	
    plmxmlFieldSingleURI		
    plmxmlFieldMultipleURI		
    plmxmlFieldExternalReference
    plmxmlFieldInternal			
    plmxmlFieldContentElement	
    \endverbatim
    etc.
*/
typedef int plmxmlFieldType;
const plmxmlFieldType	plmxmlFieldTypeBase	= 0x00000000;

const plmxmlFieldType	plmxmlFieldUnset						= plmxmlFieldTypeBase;
const plmxmlFieldType	plmxmlFieldLogical						= plmxmlFieldTypeBase + 1;
const plmxmlFieldType	plmxmlFieldInt							= plmxmlFieldTypeBase + 2;
const plmxmlFieldType	plmxmlFieldDouble						= plmxmlFieldTypeBase + 3;
const plmxmlFieldType	plmxmlFieldString						= plmxmlFieldTypeBase + 4;	// unicode UChar

const plmxmlFieldType	plmxmlFieldSingleReference				= plmxmlFieldTypeBase + 5;
const plmxmlFieldType	plmxmlFieldMultipleReference			= plmxmlFieldTypeBase + 6;
const plmxmlFieldType	plmxmlFieldSingleElement				= plmxmlFieldTypeBase + 7;
const plmxmlFieldType	plmxmlFieldMultipleElement				= plmxmlFieldTypeBase + 8;
const plmxmlFieldType	plmxmlFieldSingleURI					= plmxmlFieldTypeBase + 9;
const plmxmlFieldType	plmxmlFieldMultipleURI					= plmxmlFieldTypeBase + 10;
const plmxmlFieldType	plmxmlFieldExternalReference			= plmxmlFieldTypeBase + 11;
const plmxmlFieldType	plmxmlFieldInternal						= plmxmlFieldTypeBase + 12;
const plmxmlFieldType	plmxmlFieldContentElement				= plmxmlFieldTypeBase + 13;

const plmxmlFieldType	plmxmlFieldMatrix						= plmxmlFieldTypeBase + 19;
const plmxmlFieldType	plmxmlFieldVector						= plmxmlFieldTypeBase + 20;

const plmxmlFieldType	plmxmlFieldTypeCreateBase				= plmxmlFieldTypeBase + 10000;

////////////////////////////////////////////////////////////////////////////
//! FieldType structure used by generic plmxml::Object functions.
/*!
	Combines name, class and type information for fields.
*/
struct FieldType
{
    //! Field name
	String			m_Name;
    //! Field class
	plmxmlClass		m_Class;
    //! Field type
	plmxmlFieldType	m_Type;
};

////////////////////////////////////////////////////////////////////////////
//! FieldInfo class
/*!
	Provides detailed information for fields (attribute,element or content)
	of an Object.
*/
class PLMXML_API FieldInfo
{
	//! Internal Field
	FieldDescriptor*	m_pDescriptor;

public:

	//! Constructor.
	/*!
		Constructs an empty FieldInfo object
	*/
	FieldInfo( void );

	//! Internal constructor.
	FieldInfo( FieldDescriptor* pFieldDescriptor );

	//! Copy constructor.
	/*!
		@param	info	The existing FieldInfo instance to create this from.
	*/
	FieldInfo( const FieldInfo& info );

	//! Assignment operator.
	/*!
		@param	info	The FieldInfo instance to set the value of this to.
		@returns		Updated FieldInfo instance with the same value as info.
	*/
	FieldInfo& operator=( const FieldInfo& info );

	//! Destructor.
	~FieldInfo( void );

	//! Returns the name of this field.
	/*!
		@returns	The name of this field.
	*/
	const String& GetName( void ) const;

	//! Returns the type of this field.
	/*!
		@returns	The type of this field.
	*/
	plmxmlFieldType GetType( void ) const;

	//! Returns the class of this field
	/*!
		@returns	The class of the field. 
		
		The returned class will be be dependent on the type of the field as follows:

        \verbatim
		plmxmlFieldSingleURI
		plmxmlFieldMultipleURI
		plmxmlFieldSingleReference
		plmxmlFieldMultipleReference	The class of the type of elements that can be referenced 
										from this field. 

		plmxmlFieldSingleElement			
		plmxmlFieldMultipleElement		The class of the element 
										(plmxmlClassPart,plmxmlClassDocument, ...)

		plmxmlFieldContentElement		The class of the content element. May be one of:
											plmxmlFieldDouble
											plmxmlFieldInteger
											plmxmlFieldString
											plmxmlFieldLogical
        \endverbatim
		
		For all other types the class will be plmxmlClassUnset.
	*/
	plmxmlClass	GetClass( void ) const;

	//! Returns a string representation of the class of the field.
	/*!
		@returns	A String representation of the class of the field. If no class
					has been set then an empty String is returned.
	*/
	const String& GetClassString( void ) const;

	//! Returns any default value for the field.
	/*!
		@returns	The default value for the field. If there is no default value then 
					an empty String is returned.
	*/
	const String& GetDefaultValue( ) const;

	//! Returns whether this field has a default value.
	/*!
		@returns	<Code>TRUE</Code> if this field has a default value - <Code>FALSE</Code> 
					otherwise.
	*/
	logical HasDefaultValue( void ) const;

	//! Whether this field is a required field.
	/*!
		@returns	<Code>TRUE</Code> if this field is required - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsRequired( void ) const;

	//! Whether this field represents an enumeration.
	/*!
		@returns	<Code>TRUE</Code> if this field is an enumeration - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsEnum( void ) const;

	//! Whether this field is deprecated.
	/*!
		@returns	<Code>TRUE</Code> if this field is deprecated - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsDeprecated( void ) const;

	//! Get the possible values of the enumeration field.
	/*!
		@param	values		The returned allowed values of the enumeration field. If this is
							not an enumeration field then the returned array will be empty.
		@returns			<Code>TRUE</Code> if this an enumeration field - <Code>FALSE</Code> 
							otherwise.
	*/
	logical GetEnumerationValues( Array<String>& values ) const;

	// Whether this field is a content field.
	/*!
		@returns	<Code>TRUE</Code> if this field is a content field - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsContent( void ) const;

	//! Whether this is an element field.
	/*!
		@returns	<Code>TRUE</Code> if this field is an element field - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsElement( void ) const;

	//! Whether this is an attribute field.
	/*!
		@returns	<Code>TRUE</Code> if this field is an attribute field - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsAttribute( void ) const;

	//! Whether this is an array field.
	/*!
		@returns	<Code>TRUE</Code> if this field is an array - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsArray( void ) const;

	//! Whether this is a variable length array field.
	/*!
		@returns	<Code>TRUE</Code> if this field is a variable length array - <Code>FALSE</Code> 
					otherwise.
	*/
	logical IsVariableLengthArray( void ) const;

	//! Whether this is a reference field
	/*!
		@returns	<Code>TRUE</Code> if this field is a reference field - <Code>FALSE</Code> 
					otherwise.

		A field is a reference field if the FieldType is one of:

        \verbatim
		plmxmlFieldSingleURI
		plmxmlFieldMultipleURI
		plmxmlFieldSingleReference
		plmxmlFieldMultipleReference
		plmxmlFieldExternalReference
        \endverbatim
	*/
	logical IsReference( void ) const;

	//! Returns the length of the array.
	/*!
		@returns	The length of the array. If this is not an array then <Code>-1</Code> is returned.
					For variable length arrays a value of <Code>0</Code> is returned.
	*/
	int GetArrayLength( ) const;

	//! Compare two FieldInfo instances.
	/*!
		@param	f1	The first FieldInfo to compare.
		@param	f2	The second FieldInfo to compare.
		@returns	<Code>TRUE</Code> if the FieldInfo instances are the same - <Code>FALSE</Code> 
					otherwise.
	*/
    friend logical PLMXML_API operator==( const FieldInfo& f1, const FieldInfo& f2 );

    //! Compare two FieldInfo instances.
	/*!
		@param	f1	The first FieldInfo to compare.
		@param	f2	The second FieldInfo to compare.
		@returns	<Code>TRUE</Code> if 'f1' is less than 'f2' - <Code>FALSE</Code> 
					otherwise.
	*/
    friend logical PLMXML_API operator<( const FieldInfo& f1, const FieldInfo& f2 );

	//! Internal function.
	FieldDescriptor* GetDescriptor( ) const;
};

////////////////////////////////////////////////////////////////////////

class SelectionImpl;

//! Selection class
/*!
	Encapsulates the result of XPATH evaluation.
*/
class PLMXML_API Selection
{
public:
	SelectionImpl* m_pImpl;

public:
	//! Constructor
	Selection();

	//! Destructor
	~Selection();

	//! Get attribute value if selected.
	/*!
	@param val Selected String value. 

	If the result of the query is:

	an attribute value then this will be the attribute 
	value.

	a Content Element then this will be the content
	of the XML element represented as a String.

	an Object then this will be an empty String and the
	function will return FALSE.

	If more then one String is selected this will return
	the first one.

	@return TRUE if a String value has been selected - FALSE 
	otherwise.
	*/
	logical Get( String& val ) const;

	//! Get selected object.
	/*!
	@param val Selected Object. 

	If the result of the query is:

	an attribute value then this will be the Object that
	contains the attribute.

	a Content Element then this will be the owning 
	( parent ) Object.

	an Object then this will be the Object itself.

	If more then one Object is selected this will return
	the first one.

	@return TRUE if a Object has been selected - FALSE otherwise.
	*/
	logical Get( Object*& val ) const;

	//! Get selected objects.
	/*!
	@param vals Selected Objects. 

	If the result of the query is:

	an attribute value then this will be a single Object 
	that contains the attribute.

	one or more Content Elements then this will contain
	each owning ( parent ) Object.

	one or more Objects then this will be the Objects themselves.

	@return TRUE if one or more Objects have been selected - FALSE 
	otherwise.
	*/
	logical Get( Array<Object*>& vals ) const;

	//! Get attribute values if selected
	/*!
		@param vals		If the result of the query is:

	an attribute value then this will be a single 
	attribute value.

	one or more Content Elements then this will contain the content
	of each element represented as a String.

	one or more Objects then this will contain an empty String for
	each Object.

	The array returned will be parallel to the Object array such that items
	at a particular index map onto each other.

	@return TRUE if one or more Objects have been selected - FALSE 
	otherwise.
	*/
	logical Get( Array<String>& vals ) const;
};

/////////////////////////////////////////////////////////////////////////////

//! Stream open modes
#define PLMXML_STREAM_READ			(1<<0)
#define PLMXML_STREAM_WRITE		    (1<<1)
#define PLMXML_STREAM_APPEND		(1<<2)
#define PLMXML_STREAM_READWRITE	    PLMXML_STREAM_READ|PLMXML_STREAM_WRITE
#define PLMXML_STREAM_RANDOM_ACCESS	(1<<3)
#define PLMXML_STREAM_OVERWRITE	    (1<<4)

//////////////////////////////////////////////////////////////////////

//! Data type representing offset in a stream.
typedef unsigned long StreamOffset;

class StreamImpl;

//////////////////////////////////////////////////////////////////////
//! Base Stream class.
/*!
    Implements bit read/write operations using 32-bit cache.
    Protected member variables are used to keep track of bit-by-bit I/O.
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API Stream
{

protected:

	//! Implementation.
	mutable StreamImpl*		m_pImpl;

    //! Open the stream.
    virtual logical Open( void );

    //@{
    //! Functions to override in derived classes.
    //! Read 'length' bytes from the stream into 'ptr'. return number of bytes actually read.
    virtual int ReadBytes( void *ptr, int length ) = 0;

	//! Write 'length' bytes at 'ptr' to the stream.
    virtual logical WriteBytes( const void *ptr, int length ) = 0;

    //! Look at the next character without advancing the pointer.
	virtual logical PeekByte( char *ch ) = 0;
    //@}

public:
    //! Default constructor.
    Stream();

    //! Virtual destructor.
    virtual ~Stream();

	//! Get the mode in which this stream has been opened.
	virtual unsigned int GetMode( void ) const;

	//! Set the mode for the stream.
    /*!
        Stream can be opened for reading, writing, reading/writing or appending.
        Mode should be set to 
        \verbatim
        PLMXML_STREAM_READ, 
        PLMXML_STREAM_WRITE,
        PLMXML_STREAM_APPEND,
        PLMXML_STREAM_READWRITE,
		PLMXML_STREAM_RANDOM_ACCESS,
		PLMXML_STREAM_OVERWRITE
        \endverbatim
		or a combination of thereof
		PLMXML_STREAM_OVERWRITE is only valid in combination with PLMXML_STREAM_READ|PLMXML_STREAM_WRITE,
		it specifies whether the contents of the file are destroyed after opening.
    */
	virtual void SetMode( unsigned int mode );

	//! Get name of the stream
    const String& GetName( void ) const;

    //! Set name of the stream
    void SetName( const String& name );

    // Reading interface

    //! Read 'number' chunks of 'length' bytes from the stream into 'ptr'. Returns number of bytes read.
    /*!
        'length' parameter is used by byte-swapping procedure and
        must represent true length of single element in the array.

        For example: read an array of 10 doubles.
        \code
        double values[10];
        int nBytes = stream.Read( values, 10, sizeof(double) );
        assert( nBytes == 10*sizeof(double) );
        \endcode
    */
    virtual int Read( void *ptr, int number, int length, logical compression=FALSE );

    //! Look at the next character without advancing the pointer.
	virtual logical Peek( char *ch );

    // Writing interface
    //! Write 'number' chunks of 'length' bytes at 'ptr' to the stream.
    virtual logical Write( const void *ptr, int number, int length, logical compression=FALSE );

	//! Sets the stream position to the given offset for the next read or write
	virtual logical Seek( const StreamOffset& offset );

	//! Returns the current stream position
	virtual logical Tell( StreamOffset& offset ) const;

	//! Rewind to start of stream (equivalent to Seek(0))
	virtual logical Rewind();

	//! Return stream length
	virtual logical GetLength( unsigned long& length ) const;

	//! Set stream length
	virtual logical SetLength(unsigned long length);

	//! Flush the Stream
	virtual logical Flush( );

    //! Close the stream.
    virtual logical Close( void );

	//! Sets the position within the stream.
	/*!
		@param	offset	An offset in bytes relative to the start of the stream.
		@returns		TRUE on success or FALSE otherwise.
	*/
	logical Seek64( unsigned long long offset );

	//! Obtains the current position within the stream.
	/*!
		@param	offset	The offset in bytes relative to the start of the stream.
		@returns		TRUE on success or FALSE otherwise.
	*/
	logical Tell64( unsigned long long& offset ) const;

	//! Returns the length of ths stream.
	/*!
		@param	length	The length of the stream in bytes.
		@returns		TRUE on success or FALSE otherwise.
	*/
	logical GetLength64( unsigned long long& length ) const;

	//! Sets the length of ths stream.
	/*!
		@param	length	The required length of the stream in bytes.
		@returns		TRUE on success or FALSE otherwise.
	*/
	logical SetLength64( unsigned long long length );

	//! Internal Function.
	virtual StreamImpl* GetImplementation( ) const;
};

typedef Stream RandomAccessStream;

class FileStreamImpl;

//////////////////////////////////////////////////////////////////////
//! FileStream class.
/*!
    Implements OS file based stream.
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API FileStream : public Stream
{

protected:

	//! Open the stream using 'm_FileName' and 'm_Mode'
    virtual logical Open( void );

    //@{
    //! Stream function to override
    /*!
        Example of basic override:
        \code
        int YourStream::ReadBytes( void *ptr, int length )
        {
            if( !m_Stream )
                return FALSE;

            if( length <= 0 )
                return TRUE;

            int res = fread( ptr, 1, length, m_Stream );

            return res;
        }
        logical YourStream::PeekByte( char *ch )
        {
	        char c;
	        if ( fread( &c, 1, 1, m_Stream ) == 1 )
	        {
		        ungetc( c, m_Stream );
		        *ch = c;
		        return TRUE;
	        }
	        else
		        return FALSE;
        }
        logical YourStream::WriteBytes( const void *ptr, int length )
        {
            if( !m_Stream )
                return FALSE;

            if( length <= 0 )
                return TRUE;

            int res = fwrite( ptr, 1, length, m_Stream );

            return (res==length);
        }
        \endcode
    */
    //! Read 'length' bytes from the stream into 'ptr', returns number of bytes read.
    virtual int ReadBytes( void *ptr, int length );

    //! Write 'length' bytes at 'ptr' to the stream.
    virtual logical WriteBytes( const void *ptr, int length );

    //! Look at the next character without advancing the pointer.
	virtual logical PeekByte( char *ch );
    //@}

public:
    //! Default constructor.
    /*!
        This constructor does not open the stream.
        FileStream::Open( filename, mode ) method 
        should follow the constructor to open the stream.
    */
    FileStream();

    //! Constructor.
    /*!
        This constructor opens the stream using 'filename' and 'mode'.

        'mode' has the following values:
        \verbatim
        PLMXML_STREAM_READ       - for input streams
        PLMXML_STREAM_WRITE      - for output streams
        PLMXML_STREAM_APPEND     - for output streams appending at the end of the file.
        PLMXML_STREAM_READWRITE  - for input / output streams
        \endverbatim
    */
    FileStream( const String& filename, int mode );

    //! Virtual destructor. Stream will be closed if still open.
    virtual ~FileStream();

    //! Open the stream using 'filename' and 'mode'.
    virtual logical Open( const String& filename, int mode );

    //! Close the stream.
    virtual logical Close( void );

    //@{
    //! Additional Stream functionality to override
    /*!
        Example of basic override:
        \code
        logical YourStream::Seek( const StreamOffset& offset )
        {
	        if ( !m_Stream )
		        return FALSE;

	        return fseek( m_Stream, offset, SEEK_SET ) == 0; 
        }

        logical YourStream::Tell( StreamOffset& offset ) const
        {
	        if ( !m_Stream )
		        return FALSE;

	        offset = ftell( m_Stream );

	        return TRUE;
        }
        \endcode
    */
	//! Sets the file position to the given offset for the next read or write
	virtual logical Seek( const StreamOffset& offset );

	//! Returns the current stream position
	virtual logical Tell( StreamOffset& offset ) const;

	//! Return stream length
	virtual logical GetLength( unsigned long& length ) const;

	//! Set stream length
	virtual logical SetLength(unsigned long length);

	//! Flush the Stream
	virtual logical Flush( void );
	//@}

	//! Internal Function.
	virtual StreamImpl* GetImplementation( ) const;
};

//////////////////////////////////////////////////////////////////////
//! MemoryStream class.
/*!
    Implements "memory buffer" stream.
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API MemoryStream : public Stream
{
protected:

    //! Read 'length' bytes from the stream into 'ptr', returns number of bytes read.
    virtual int ReadBytes( void *ptr, int length );

    //! Write 'length' bytes at 'ptr' to the stream.
    virtual logical WriteBytes( const void *ptr, int length );

    //! Look at the next character without advancing the pointer.
	virtual logical PeekByte( char *ch );

	//! Increases or decreases the size of the file to 'length'.
	virtual logical GrowFile( unsigned long length );

public:
	
	//! Create an empty MemoryStream with an internal buffer
    MemoryStream();

	//! Create a MemoryStream with an external buffer
    /*! 
        'buffer' must point to a memory buffer of 
        'allocatedLength' length.
    */
	MemoryStream( void *buffer, int length, int allocatedLength );

	//! Virtual destructor.
	/*!
		Note: An external buffer will not be deleted by this.
	*/
	virtual ~MemoryStream();

    //! Return stream length
	virtual logical GetLength( unsigned long& length ) const;

	//! Sets the new stream length
	virtual logical SetLength(unsigned long length);

    //! Return a pointer to stream data
	virtual void* GetBuffer() const;

	//! Sets the file position to the given offset for the next read or write
	virtual logical Seek( const StreamOffset& offset );

	//! Returns the current stream position
	virtual logical Tell( StreamOffset& offset ) const;

	//! Flush the stream
	virtual logical Flush( void );

	//! Internal Function.
	virtual StreamImpl* GetImplementation( ) const;
};

//////////////////////////////////////////////////////////////////////
//! HTTP Stream class.
/*!
    Implements Read-Only HTTP stream.

    URL passed to the constructor is expected to be in the following format: <br>
    <b>protocol://host:port/path?query#fragment</b><br>
    where "protocol" must be "http".

    HTTPStream is based on partial content downloading mechanism. 
    
    If pre-loading is enabled using 'preLoad' constructor argument, the 
    contents of the target URL are downloaded into local buffer, 
    and all subsequent read/seek operations are performed on the local buffer.

    If pre-loading is disabled, content of the target URL is downloaded on demand,
    i.e. when Read operations are performed, caching also takes place.

*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API HTTPStream : public Stream
{
protected:

    //! Read 'length' bytes from the stream into 'ptr', returns number of bytes read.
    virtual int ReadBytes( void *ptr, int length );

    //! Write 'length' bytes at 'ptr' to the stream.
    virtual logical WriteBytes( const void *ptr, int length );

    //! Look at the next character without advancing the pointer.
	virtual logical PeekByte( char *ch );

	//! Sets the stream position to the given offset for the next read or write
	virtual logical Seek( const StreamOffset& offset );

	//! Returns the current stream position
	virtual logical Tell( StreamOffset& offset ) const;

	//! Rewind to start of stream (equivalent to Seek(0))
	virtual logical Rewind();

	//! Return stream length
	virtual logical GetLength( unsigned long& length ) const;

	//! Flush the Stream
	virtual logical Flush();

public:
	
	//! Create an HTTPStream and open it, optionally pre-loading URL contents.
    HTTPStream( const String& url, logical preLoad=FALSE );

    //! Destructor
    virtual ~HTTPStream();

	//! Internal Function.
	virtual StreamImpl* GetImplementation( ) const;

	static logical GetRedirect( const String& uri, String& redirect );
};

#if defined(__MACHINE_I386) || defined(__MACHINE_NTIA)
template class PLMXML_API Array<int>;
#endif

//////////////////////////////////////////////////////////////////////
//! Variable length key->data map class.
/*!
    Template class.
    Instantiations should only include 'simple' objects,
    i.e. objects without any virtual functions as well as 
    primitive types. These 'simple' classes must implement 
    operators "==" and "<" as the Map class uses binary search mechanism.
*/
//////////////////////////////////////////////////////////////////////
template <class K, class C> 
class Map 
{
private:
    K           m_LastKey;
	Array<K>    m_pKeySet;
	Array<C>    m_pObjSet;
	Array<int>  m_Indices;

private:
    logical Search( const K& key, int& idx ) const
    { 
        // m_Indices is ordered
        int first = 0;
        int last  = m_pKeySet.GetSize()-1;

        while( first<=last )
        { 
            // the number midway between first and last;
            int mid = (first+last)/2; 

            const K& e = m_pKeySet.GetData()[m_Indices.GetAt(mid)];

            if( e == key ) 
            {
                // the array cell at mid is equal to key
                idx = mid;
                return TRUE;
            }
            else if( key < e )   // key is less than  the array cell at mid
                last = mid - 1;  // search the left half of the array
            else                 // key is definitely greater
                first = mid + 1; // search the right half of the array

        }

        idx = first;

        return FALSE;
    }

public:
    //! Default constructor.
	Map() 
    {
    }
	//! Constructs a map with the supplied initial storage capacity.
	Map( int length ) 
	:	m_pKeySet( length ),
		m_pObjSet( length ),
		m_Indices( length )
	{

    }
    //! Default virtual destructor.
	virtual ~Map()
    {
    }

    //! Add new 'key' and corresponding data object 'c'
	/*!
	If 'key' is already present, another copy of 'key' is added
	*/
	void Add( const K& key, const C& c ) 
	{ 
        m_LastKey = key;

        int idx;
        Search( key, idx );
        
        // Array<T> is a data buffer
        // m_Indices contain indices to this buffer
		m_pKeySet.Add( key );
		m_pObjSet.Add( c );
        int n = m_pKeySet.GetSize();
        m_Indices.InsertAt( idx, n-1 );
	}

    //! Remove 'key' and corresponding data object 'c', if present
	/*!
	If there is more than one copy of 'key', one of them will be removed
	*/
	void Remove( const K& key )
	{
        int idx, val_idx;
        if( Search( key, idx ) )
            val_idx = m_Indices[idx];
        else
            val_idx = -1;

        if( val_idx != -1 )
        {
		    m_pKeySet.RemoveAt( val_idx );
		    m_pObjSet.RemoveAt( val_idx );
            m_Indices.RemoveAt( idx );

			// indices greater than val_idx need to be reduced by 1 to
			// account for part of the key array being shifted 
			int len = m_Indices.GetSize();
			for ( int i = 0; i < len; i++ )
			{
				if ( m_Indices[i] > val_idx )
					m_Indices[i] = m_Indices[i] - 1;
			}
        }
	}

    //! Find index of object referenced with 'key'.
	int LookupIndex( const K& key ) const
	{
        int idx;
        if( Search( key, idx ) )
            return m_Indices[idx];
        else
            return -1;
	}

    //! Find object referenced with 'key'.
	logical Lookup( const K& key, C& value ) const
	{
        int i = LookupIndex( key );

        if( i != -1 )
        {
            value = m_pObjSet.GetAt(i);
            return TRUE;
        }
        
        return FALSE;
	}

    //! Get number of elements in the map.
	int GetSize( void ) const 
    { 
        return m_pKeySet.GetSize();
    }
    //! Get value at index 'i'.
	const C& GetValue( int i ) const 
    { 
        return m_pObjSet.GetAt(i);
    }
    //! Get key at index 'i'.
	const K& GetKey( int i ) const 
    { 
        return m_pKeySet.GetAt(i);
    }
    //! Get last added key.
    const K& GetLastKey( void ) const
    {
        return m_LastKey;
    }
    //! Remove all keys and objects, clear the map.
	void RemoveAll( void )
	{
		m_pKeySet.RemoveAll();
		m_pObjSet.RemoveAll();
        m_Indices.RemoveAll();
    }
};

//////////////////////////////////////////////////////////////////////
class VectorImpl;
//! 3D Vector class
/*!
    Implements position or displacement in 3D space. 
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API Vector 
{
	VectorImpl*		m_pImpl;

public:

    //! Default constructor
    Vector();

	//! Copy constructor
	Vector( const Vector& v );

	//! Constructor with three doubles
	Vector( double x, double y, double z );

	//! Constructor with an array of doubles containing at least three values.
	Vector( const double* array );

	//! Constructor with VectorField.
	Vector( Object* pVecField );

    //! Destructor
    virtual ~Vector();

    //@{
	//! Read-only vector components access.
	double operator[]( int i ) const; 
	double Component( int i ) const;
	double x( void ) const;
	double y( void ) const;
	double z( void ) const;
    //@}

    //@{
	//! Read-write vector components access
	double& operator[]( int i );
	double& Component( int i );
	double& x( void );
	double& y( void );
	double& z( void );
    //@}

	//! Assignment operator
	Vector& operator=( const Vector& v );

    //@{
	//! Scale a vector
    friend PLMXML_API Vector operator*( double, const Vector& );
    friend PLMXML_API Vector operator*( const Vector&, double );
    friend PLMXML_API Vector operator/( const Vector&, double );
    //@}

    //@{
    //! Scale this vector
	const Vector& operator*=( double );
	const Vector& operator/=( double );
    //@}

	//! Add two vectors
    friend PLMXML_API Vector operator+( const Vector&, const Vector& );

	//! Subtract vectors
    friend PLMXML_API Vector operator-( const Vector&, const Vector& );

    //! Add a vector to this vector
	const Vector& operator+=( const Vector& );

	//! Reverse vector
	friend PLMXML_API Vector operator-( const Vector& );

	//! Subtract a vector from this vector
	const Vector& operator-=( const Vector& );

	//! Dot product of two vectors.
    friend PLMXML_API double operator%( const Vector&, const Vector& );

	//! Cross product of vectors
    friend PLMXML_API Vector operator*( const Vector&, const Vector& );

	//! Length of this vector
	double Length( void ) const;

	//! Transform a vector
    friend PLMXML_API Vector operator*( const Transf&, const Vector& );

    //! Transform this vector
	const Vector& operator*=( const Transf& );

	//! Make a unit vector
	friend PLMXML_API UnitVector Normalise( const Vector& );

    //! Make unit vector from this vector
	UnitVector Normalise( void ) const;

	//! Check if two vectors are parallel to given tolerance
	friend PLMXML_API logical Parallel( const Vector&, const Vector&, double tol );

	//! Check if two vectors are parallel to a tolerance of 1.0e-11
	friend PLMXML_API logical Parallel( const Vector&, const Vector& );

	//! Check if two vectors are anti-parallel to given tolerance
	friend PLMXML_API int     ParallelSign( const Vector&, const Vector&, double tol );

	//! Check if two vectors are anti-parallel to a tolerance of 1.0e-11
	friend PLMXML_API int     ParallelSign( const Vector&, const Vector& );

	//! Check if two vectors are perpendicular to given tolerance
	friend PLMXML_API logical Perpendicular( const Vector&, const Vector&, double tol );

	//! Check if two vectors are perpendicular to a tolerance of 1.0e-11
	friend PLMXML_API logical Perpendicular( const Vector&, const Vector& );
	
	//! Check if two vectors are equal to given tolerance
    friend PLMXML_API logical Equal( const Vector&, const Vector&, const double tol );

	//! Check if two vectors are equal to a tolerance of 1.0e-8
    friend PLMXML_API logical Equal( const Vector&, const Vector& );
	
	//! Check if two vectors are coincident to RES_LINEAR
    friend PLMXML_API logical operator==( const Vector&, const Vector& );

    //! Check if two vectors are coincident to RES_LINEAR
    friend PLMXML_API logical operator!=( const Vector&, const Vector& );
};

//////////////////////////////////////////////////////////////////////
//! Unit 3D Vector class
/*!
    Implements displacement in 3D space of unit length.
*/
//////////////////////////////////////////////////////////////////////
class PLMXML_API UnitVector: public Vector 
{
public:

    //! Default constructor
	UnitVector();

	//! Make a unit vector from three components. Normalises result
	UnitVector( double, double, double );

	//! Make a unit vector from three doubles. Normalises result
	UnitVector( const double* array );

    //! Destructor
	~UnitVector();
};

//////////////////////////////////////////////////////////////////////
class TransfImpl;
//! Transf class.
/*!
    Transf class
    
    4x4 transformation matrix, acts on a vector by multiplying on the 
	left:
    \verbatim  
     (             , Tx ) ( x )        ( x')
     (      R      , Ty ) ( y )   =    ( y')
     (             , Tz ) ( z )        ( z')
     ( Px, Py, Pz,   S  ) ( w )        ( w')

	 i.e. taking w = 1, ( x, y, z, 1 ) maps to ( x'/w', y'/w', z'/w', 1 )
    
    where
    
    R =  a non singular transformation matrix.
         This matrix contains the rotation, reflection, non-uniform scaling
         and shearing components.
    T =  a translation vector.
    P =  perspective terms in viewing transformations.
         Must be zero in transformations used for modelling.
    S =  a global scaling factor. It has to be greater than zero.
         Its value is the inverse of the global scale.
    
    The matrix components above are:
    
     ( [0][0]  [0][1]  [0][2]  [0][3] )
     ( [1][0]  [1][1]  [1][2]  [1][3] )
     ( [2][0]  [2][1]  [2][2]  [2][3] )
     ( [3][0]  [3][1]  [3][2]  [3][3] )
    \endverbatim
    
*/
class PLMXML_API Transf 
{
	TransfImpl*		m_pImpl;

public:

    //! Make identity transform
    void Initialise( void );

    //! Convert to 4x4 matrix.
    void ToMatrix4x4( double matrix[4][4] ) const;

    //! Convert from 4x4 matrix.
    void FromMatrix4x4( double matrix[4][4] );
public:

    //@{
    //! Transf constructors.
    //! Default constructor. Makes identity transformation.
    Transf();

	//! Copy constructor
	Transf( const Transf& );

	//! Construct translation transformation.
	Transf( const Vector& offset );

	//! Construct rotation transformation around 'axis' by 'angle' in radians.
	Transf( const UnitVector& axis, double angle );

	//! Construct coordinate transformation.
	/*! 
	Construct a transform which maps (0, 0, 0), (1, 0, 0) and (0, 1, 0) to
	the given vectors.
	*/
	Transf( const Vector& origin, const UnitVector& xAxis, const UnitVector& yAxis );

	//! Construct scale transformation.
	Transf( double scale );
    //@}

    //! Destructor
    ~Transf();

    //! Create inverse transform.
    Transf Inverse() const;

	//! Get the scale component of the transform.
	double GetScale( ) const;

	//! Get the perspective component of the transform.
	const Vector& GetPerspective( ) const;

	//! Get the translation component of the transform.
	const Vector& GetTranslation( ) const;

	//! Get the rotation component of the transform
	void GetRotation( double rotation[3][3] ) const;

    //! Transform this transformation (right-multiply by given Transf)
	const Transf& operator*=( const Transf& );

    //! Transform a transformation (multiply)
    friend Transf PLMXML_API operator*( const Transf&, const Transf& );

	//! Assignment operator
	Transf& operator=( const Transf& t );
};

//////////////////////////////////////////////////////////////////////
class BoxBoundImpl;

//! Bounding box class.
/*!
    Represents coordinate system aligned bounding box in 3D space.
*/
class PLMXML_API BoxBound
{
	BoxBoundImpl*	m_pImpl;

public:

    //! Default constructor
	BoxBound();

    //! Copy constructor
	BoxBound( const BoxBound& b );

    //! Constructor from a centre point and a corner
	BoxBound( const Vector& centre, const Vector& halfWidths );

    //! Destructor
	~BoxBound();

	//! Assignment operator
	BoxBound& operator=( const BoxBound& b );

    //! Check if a point is contained by the bounding box.
	logical Contains( const Vector &v ) const;

	//! Check if bound is set.
	logical IsSet() const;

    //! Expand the bounding box to include the point.
	void Expand( const Vector &v );

    //! Expand the bounding box to include other bounding box.
	void Expand( const BoxBound &b );

    //! Get lower corner.
    const Vector& GetLow( void ) const;

    //! Get high corner.
    const Vector& GetHigh( void ) const;

    //! Get centre of the bounding box.
    Vector GetCentre( void ) const;

    //! Get half of the main diagonal.
    Vector GetHalfWidths( void ) const;
};

//////////////////////////////////////////////////////////////////////
class SphereBoundImpl;

//! Bounding sphere class.
/*!
    Represents bounding sphere in 3D space.
*/
class PLMXML_API SphereBound
{
	SphereBoundImpl*	m_pImpl;

public:

    //! Default constructor
	SphereBound();

    //! Copy constructor
	SphereBound( const SphereBound& b );

    //! Constructor from a centre point and a radius
	SphereBound( const Vector &centre, double radius );

	//! Assignment operator
	SphereBound& operator=( const SphereBound& s );

    //! Destructor
	~SphereBound();

    //! Check if point is contained within the bounding sphere.
	logical Contains( const Vector &v ) const;

	//! Check if bound is set.
	logical IsSet() const;

    //! Expand the bounding sphere to include a point
	void Expand( const Vector &v );

    //! expand the bounding sphere to include other bounding sphere
	void Expand( const SphereBound &b );

    //! Get centre of the bounding sphere.
    const Vector& GetCentre( void ) const;

    //! Get radius of the bounding sphere.
    double GetRadius( void ) const; 
};


//////////////////////////////////////////////////////////////////////
//@{ \name PLM XML Error Codes

/*! \defgroup ErrorHandling Error Handling
*/

/*! \ingroup ErrorHandling
    Error Code type.
*/
typedef int ErrorCode;

/*! \ingroup ErrorHandling
    Generic Error codes base.
*/
const ErrorCode			ErrorCodeBase					= 0x00000000;


/*! \ingroup ErrorHandling
    PLM XML Error Codes
*/
const ErrorCode			ErrorCodeOK						= ErrorCodeBase;
const ErrorCode			ErrorCodeUnset					= ErrorCodeBase + 0x00000001;
const ErrorCode			ErrorCodeFailed					= ErrorCodeBase + 0x00000002;
const ErrorCode			ErrorCodeOutOfMemory			= ErrorCodeBase + 0x00000003;
const ErrorCode			ErrorCodeLoadFailed				= ErrorCodeBase + 0x00000004;
const ErrorCode			ErrorCodeSaveFailed				= ErrorCodeBase + 0x00000005;
const ErrorCode			ErrorCodeNotImplemented			= ErrorCodeBase + 0x00000006;
const ErrorCode			ErrorCodeMultipleErrors			= ErrorCodeBase + 0x00000007;
const ErrorCode			ErrorCodeNotLicensed            = ErrorCodeBase + 0x00000008;

const ErrorCode			ErrorCodeInvalidIndex			= ErrorCodeBase + 0x00000010;
const ErrorCode			ErrorCodeFileOpenError			= ErrorCodeBase + 0x00000011;
const ErrorCode			ErrorCodeDivisionByZero			= ErrorCodeBase + 0x00000012;
const ErrorCode			ErrorCodeInvalidArgument		= ErrorCodeBase + 0x00000013;
const ErrorCode			ErrorCodeAlreadyExists			= ErrorCodeBase + 0x00000014;

const ErrorCode			ErrorCodeInitRegisterHandlers	= ErrorCodeBase + 0x00000050;
const ErrorCode			ErrorCodeInitInternalData		= ErrorCodeBase + 0x00000051;
const ErrorCode			ErrorCodeInitParsers			= ErrorCodeBase + 0x00000052;
const ErrorCode			ErrorCodeInitSchema				= ErrorCodeBase + 0x00000053;
const ErrorCode         ErrorCodeInitPlugins            = ErrorCodeBase + 0x00000054;

const ErrorCode			ErrorCodeStreamAlreadyExists	= ErrorCodeBase + 0x00000100;
const ErrorCode			ErrorCodeStreamOpen				= ErrorCodeBase + 0x00000101;
const ErrorCode			ErrorCodeStreamWrite			= ErrorCodeBase + 0x00000102;
const ErrorCode			ErrorCodeStreamRead				= ErrorCodeBase + 0x00000103;
const ErrorCode			ErrorCodeStreamSeek				= ErrorCodeBase + 0x00000104;
const ErrorCode			ErrorCodeStreamAccess			= ErrorCodeBase + 0x00000105;
const ErrorCode			ErrorCodeStreamInvalidName		= ErrorCodeBase + 0x00000105;

const ErrorCode			ErrorCodeGroup					= ErrorCodeBase + 0x00000200;
const ErrorCode			ErrorCodeDuplicateId			= ErrorCodeBase + 0x00000201;
const ErrorCode			ErrorCodeInvalidId				= ErrorCodeBase + 0x00000202;
const ErrorCode			ErrorCodeValidateFailed			= ErrorCodeBase + 0x00000203;
const ErrorCode			ErrorCodeLocateFailed			= ErrorCodeBase + 0x00000204;
const ErrorCode			ErrorCodeResolveFailed			= ErrorCodeBase + 0x00000205;
const ErrorCode			ErrorCodeMissingAttribute		= ErrorCodeBase + 0x00000206;
const ErrorCode			ErrorCodeInvalidURI				= ErrorCodeBase + 0x00000207;
const ErrorCode			ErrorCodeXML					= ErrorCodeBase + 0x00000208;
const ErrorCode			ErrorCodeAdapterQueryFailed		= ErrorCodeBase + 0x00000209;
const ErrorCode			ErrorCodeAdapterPointerFailed	= ErrorCodeBase + 0x0000020A;
const ErrorCode			ErrorCodeInvalidAttributeValue	= ErrorCodeBase + 0x0000020B;
const ErrorCode			ErrorCodeAdapterExportFailed	= ErrorCodeBase + 0x0000020C;
const ErrorCode			ErrorCodeInvalidAttribute		= ErrorCodeBase + 0x0000020D;
const ErrorCode			ErrorCodeSelectionFailed		= ErrorCodeBase + 0x0000020E;
const ErrorCode			ErrorCodeSerialisation			= ErrorCodeBase + 0x0000020F;
const ErrorCode			ErrorCodeInvalidEncoding		= ErrorCodeBase	+ 0x00000210;
const ErrorCode			ErrorCodeInvalidProperty		= ErrorCodeBase + 0x00000211;

const ErrorCode			ErrorCodeStorageOpen			= ErrorCodeBase + 0x00000300;
const ErrorCode			ErrorCodeStorageOpenFail		= ErrorCodeBase + 0x00000301;
const ErrorCode			ErrorCodeStorageClosed			= ErrorCodeBase + 0x00000302;

const ErrorCode			ErrorCodeJava					= ErrorCodeBase + 0x00000400;

/*! \ingroup ErrorHandling
    The Error Severity enumeration
*/
enum ErrorSeverity
{
	ErrorSeverityUnset,
	ErrorSeverityMessage,
	ErrorSeverityWarning,
	ErrorSeverityError,
	ErrorSeveritySevere,
	ErrorSeverityFatal,
	ErrorSeverityMultiple
};
//@}

class ErrorImpl;

//////////////////////////////////////////////////////////////////////
//! Error class.
/*! \ingroup ErrorHandling
	The Error class stores the code, severity and message associated
	with a toolkit error.
*/
class PLMXML_API Error
{
	ErrorImpl*	m_pImpl;

public:

	//! Constructor
	Error();

	//! Constructor
	Error( ErrorCode code, ErrorSeverity severity );

	//! Constructor - assume severity ErrorSeverityError
	Error( ErrorCode code );

	//! Constructor - assume severity ErrorSeverityError
	Error( ErrorCode code, const String& msg );

	//! Constructor
	Error( ErrorCode code, ErrorSeverity severity, const String& msg );

	//! Constructor
	Error( ErrorCode code, ErrorSeverity severity, const String& msg, void* pData );

	//! Copy constructor
	Error( const Error& e );

	//! Destructor
	~Error();

	//! Overloaded assignment operator
	Error& operator=(const Error &error);

	//! Get the Error Code
	ErrorCode GetCode( void ) const;

	//! Set the Error Code
	void SetCode( ErrorCode code );

	//! Get the Error Severity
	ErrorSeverity GetSeverity( void ) const;

	//! Set the Error Severity
	void SetSeverity( ErrorSeverity );

	//! Get the error message
	const String& GetMessage( void ) const;

	//! Set the error message
	void SetMessage( const String& msg );

	//! Append to the message
	void AddMessage( const String& msg );	

	//! Set data associated with error
	void SetData( void* pData );

	//! Get the data associated with the error
	void* GetData( void ) const;
};

//////////////////////////////////////////////////////////////////////
class ResultImpl;

//! Result class.
/*! \ingroup ErrorHandling
	The Result class stores the outcome of a toolkit operation - success, or
	one or more error or warning conditions.
*/
class PLMXML_API Result 
{

private:

	ResultImpl*	m_pImpl;

public:
	//! Constructor, no errors
	Result();

	//! Constructs a new Result with the specified Error.
	Result( const Error& error );

	//! Constructor, given an error code, severity is set to ErrorSeverityError
	Result( ErrorCode Code );

	//! Constructor, given an error code and msg, severity is set to ErrorSeverityError
	Result( ErrorCode Code, const String& msg );

	//! Constructor, given an error code, severity and msg
	Result( ErrorCode Code, ErrorSeverity severity, const String& msg );

	//! Constructor, given an error code, severity, msg and data
	Result( ErrorCode Code, ErrorSeverity severity, const String& msg, void* pData );

	//! Copy constructor
	Result( const Result& r );

	//! Destructor
	virtual ~Result();

	//! Overloaded assignment operator
	Result& operator=(const Result &error);

	//! Get the Error Code
	/*!
	If there is more than one error, ErrorCodeMultipleErrors is returned
	*/
	ErrorCode GetCode( void ) const;

	//! Return the number of errors.
	/*!
	A toolkit function may return a number of error or warning conditions.
	*/
	int NumberOfErrors( void ) const;

	//! Get the i'th Error object.
	/*!
	This is a pointer to an internal Error object, it must not be
	deleted.
	*/
	Error* GetError( int i ) const;

	//! Returns the error message, blank string if no error, concatenated strings if multiple.
	/*!
	If there is more than one error, the error messages are concatenated,
	separated by CR.
	*/
	const String& GetMessage( void ) const;

	//! Add an error to the result
	/*!
	The Error object is copied into the Result.
	*/
	void AddError( const Error& error );

	//! Add an error to the result
	void AddError( ErrorCode code, const String& msg );

	//! Add an error to the result
	void AddError( ErrorCode code, ErrorSeverity severity, const String& msg );

	//! Add an error to the result
	void AddError( ErrorCode Code, ErrorSeverity severity, const String& msg, void* pData );

	//! Add the errors from another Result into this one.
	void Merge( const Result& r );
	
	//! Return true if operation succeeded - no errors
	logical Ok( void ) const;

	//! Return true if operation had an error
	logical HasError( void ) const;
};

//////////////////////////////////////////////////////////////////////
class ExceptionImpl;

//! Exception class.
/*! \ingroup ErrorHandling
    Exceptions may be thrown by some operations where
    it is not possible to return an error status. For example,
    constructor of FileStream class will throw an exception should
    it fail to open the file.
*/
class PLMXML_API Exception
{
	ExceptionImpl*	m_pImpl;

public:

	//! Constructs an Exception from an ErrorCode
    Exception( ErrorCode code );

	//! Constructs an Exception from an ErrorCode and a description  
    Exception( ErrorCode code, const String& text );

	//! Copy constructor.
	Exception( const Exception& code );

	//! Destructor.
	~Exception( );

	//! Overloaded assignment operator.
	Exception& operator=( const Exception& e );

	//! Get the error code.
    ErrorCode GetCode( void ) const;

	//! Set the error Code
	void SetCode( ErrorCode code );

	//! Return error description of the exception object.
    const String& GetMessage( void ) const;

	//! Set the error description of the exception object
	void SetMessage( const String& msg );
};

//////////////////////////////////////////////////////////////////////

//! EnumBase class
/*!
    Base class for all PLM XML classes representing enumerations.
*/
class PLMXML_API EnumBase
{
protected:
    //! Internal
	static int      m_iCurrField;

	//! Stores built in enumeration Value
	const char*     m_cType;

	//! Stores user added enumeration  Value
	mutable String	m_ustrType;

public:

    //! Constructor
	EnumBase();

    //! Destructor
	virtual ~EnumBase( );

    //! Internal
	static int Init( );

    //! Return the value of this enum as String
	const String& ToString( ) const;

    //! Set this object equal to 'Value'. Returns FALSE if 'Value' does not match any allowable values.
	virtual logical Set( const String& Value ) = 0;

    //! Set this object equal to 'Value'. Returns FALSE if 'Value' does not match any allowable values.
	virtual logical Set( const char* Value ) = 0;
};

//////////////////////////////////////////////////////////////////////

//! enum returned by Visit function during traversal
enum plmxmlTraverseResult
{
	plmxmlTraverseContinue,
	plmxmlTraverseAbortLocal,
	plmxmlTraverseAbort
};

//////////////////////////////////////////////////////////////////////
class TraverseContextImpl;

//! Base class for context class used during traversal
class PLMXML_API TraverseContext
{
	//! Internal field
	TraverseContextImpl*	m_pImpl;

public:

	//! Constructor
	TraverseContext();

	//! Destructor
	virtual ~TraverseContext();

	//! Function that is called during traversal for each object visited. 
	/*!
		The return value determines how the traversal will continue.
	*/
	virtual plmxmlTraverseResult Visit(Object *pObject) = 0;

	//! Whether to follow any URI
	logical GetFollowURI();

	//! Sets whether to follow any URI
	void SetFollowURI( logical followURI );

	//! Internal function
	TraverseContextImpl* GetImplementation( ) const;
};

//////////////////////////////////////////////////////////////////////

class Object;
class PointerImpl;

/*! \defgroup AdapterControl Adapter Control Strings
	see plmxml_api::Pointer class.
*/

//////////////////////////////////////////////////////////////////////

//! Pointer Escape/Unescape control codes
#define PLMXML_ESCAPE_NONE		(0)
#define PLMXML_ESCAPE_SPACE		(1<<0)
#define PLMXML_ESCAPE_HASH		(1<<1)
#define PLMXML_ESCAPE_PERCENT	(1<<2)

#define PLMXML_ESCAPE_STANDARD	PLMXML_ESCAPE_SPACE | PLMXML_ESCAPE_HASH | PLMXML_ESCAPE_PERCENT
#define PLMXML_ESCAPE_EXTENDED	(1<<3)

//////////////////////////////////////////////////////////////////////
//! class representing PLMXML Pointer.
/*! 
    Implements PLMXML Pointer parsing into arrays (chain) of 
    adapter types, control strings and URI.

    \verbatim
    scheme://host:port/path#PLMXML(AAA-doc/xxxxx/BBB-doc/id=fred/CCC-doc/yyyyy/XT-doc)
    ^^^^^^^^^^^^^^^^^^^^^^^                      ^^^^^^^^^^^^^^^
    URI                                          adapter component

    BBB-doc/id=fred
    ^^^
    adapter type

    BBB-doc/id=fred
            ^^^^^^^
            control string
    \endverbatim
*/
class PLMXML_API Pointer
{
    PointerImpl*    m_pImpl;

public:

	friend class PointerImpl;

	//! Break the URI and PLMXML Pointer string into its components.
    Result Parse( const String& ptrString );
    
    //! Default constructor
    Pointer();

    //! Copy constructor
    Pointer( const Pointer& p );

    //! Assignment operator
    const Pointer& operator=( const Pointer& s );

    //! Destructor
    ~Pointer();

    //! Construct PLMXML Pointer by parsing a String.
    Pointer( const String& ptrString );

    //! Return if this PLMXML pointer is valid, i.e contains any instructions
    logical IsValid( void ) const;

    //! Compare two PLMXML Pointers. Locator strings are not taken into account.
    friend logical PLMXML_API operator==( const Pointer& p1, const Pointer& p2 );

    //! Compare two PLMXML Pointers. Locator strings are not taken into account.
    friend logical PLMXML_API operator<( const Pointer& p1, const Pointer& p2 );

    //! Reset all components of the URI and Pointer
    void Reset( void );

    //! Reconstruct and return the 'uri' String from the stored components.
    Result Construct( String& uri );

    //! Return stored string representation of the pointer
    const String& GetString( void ) const;

    //! Set the \#fragment and re-evaluate the plmxml pointer
    void SetFragment( const String& fragment );

    //! Return if fragment represents valid PLMXML Pointer, i.e. \#PLMXML(...)
    logical HasPtrFragment( void ) const;

    //! Return number of components in the chain
    int GetAdapterCount( void ) const;

    //! Return n'th adapter type in the chain
    const String& GetAdapterType( int chainIndex ) const;

    //! Return n'th control string in the chain
    const String& GetControlString( int chainIndex ) const;

    //! Return control string of the last adapter in the chain
    const String& GetLocatorString() const;

    //! Set control string of the last adapter in the chain
    void SetLocatorString( const String& lstr );

    //! Add component to the end of the chain
	Result Add( const String& adapterType, const String& controlString );

    //! Insert component in the chain
    void Insert( int chainIndex, const String& adapterType, const String& controlString );

    //! Set n'th adapter type in the chain
    void SetAdapterType( int chainIndex, const String& adapterType );

    //! Set n'th adapter type in the chain
    void SetControlString( int chainIndex, const String& controlString );

    //!  Remove n'th component from the chain
    void Remove( int chainIndex );

    //! Remove all components
    void RemoveAll( void );

    //! Make sure that last component matches 'format'
    void EnsureFormat( const String& format );

    //! Return last component's adapter type
    const String& GetFormat( void ) const;

    //! Check whether the URI is relative (i.e. does not contain path).
	logical IsRelative() const;

    //! Return scheme of the URI.
	const String& GetScheme( void ) const;

    //! Return host of the URI.
    const String& GetHost( void ) const;

	//! Return port of the URI.
    int GetPort( void ) const;

	//! Return path of the URI.
    const String& GetPath( void ) const;

    //! Return whether path is present.
	logical HasPath( void ) const;

    //! Return filename part of the URI.
    const String& GetFile( void ) const;

    //! Return file extension part of the URI.
    const String& GetExtension( void ) const;

    //! Return filename of URI.
	const String& GetFileName( void ) const;

    //! Set filename of URI by setting file and extension components
    void SetFileName( const String& fileName ); 

    //! Return fullpath of URI.
	const String& GetFullPath( void ) const;

    //! Return basepath of URI.
	const String& GetBasePath( void ) const;

    //! Return absolutepath of URI
    const String& GetAbsolutePath( void ) const;

    //! Return netpath of URI
    const String& GetNetPath( void ) const;

    //! Return query of the URI.
    const String& GetQuery( void ) const;

    //! Return fragment of the URI.
    const String& GetFragment( void ) const;

    //! Return whether fragment is present.
	logical HasFragment( void ) const;

	// Returns the implementation of this Object
	PointerImpl* GetImplementation( ) const;

	//! Converts a string to its escaped URI representation.
	/*!
		The resultant string can then be supplied to the various SDK
		functions that accept URI arguments.

		Note: This method assumes that 'input' is not already a URI. 

		Characters in the input string will be escaped according to the value 
		of the 'flags' argument. This can be a bitwise combination of any of
		the following flags:

			PLMXML_ESCAPE_NONE

				No escaping of the input string will be performed.
			
			PLMXML_ESCAPE_SPACE		' '		as	%20
					
			PLMXML_ESCAPE_HASH		'#'		as	%23

			PLMXML_ESCAPE_PERCENT	'%'		as	%25

			PLMXML_ESCAPE_STANDARD	(DEFAULT)

				All supported characters are escaped. Equivalent to:
				
				PLMXML_ESCAPE_SPACE | PLMXML_ESCAPE_HASH | PLMXML_ESCAPE_PERCENT

			PLMXML_ESCAPE_EXTENDED

				The input string will be broken down into the individual components of 
				a URI. Each component will then be escaped as required by the URI 
				specification.
				In general this will mean that the (' ') and ('%') characters will 
				always be escaped as well as the ('#') and ('?') characters (as long 
				as they do not indicate a fragment or query component). Additional 
				characters will also be escaped dependent on the component.
				For example for a query component any ('/'), ('?'), (':'), ('@'), (',') 
				and ('$') characters will also be escaped.
		
		For example if PLMXML_ESCAPE_STANDARD is specified then:
		\verbatim
		"foo bar.txt"		->	"foo%20bar.txt"
		"foo#bar.txt"		->	"foo%23bar.txt"
		"foo%bar.txt"		->	"foo%25bar.txt"
		"foo%20bar .txt"	->	"foo%2520bar%20.txt"
		\endverbatim

		If PLMXML_ESCAPE_EXTENDED is specified then:
		\verbatim
		"foo#bar.plmxml#id7							-> "foo%23bar.plmxml#id7"
		"foo.txt?date=2010/04/14;time=09:04:29"		-> "foo.txt?date=2010%2f04%2f14;time=09%3a04%3a29"
		\endverbatim

		@param	input	Input string to escape.
		@param	output	Output escaped string.
		@param	flags	Set of options to control which characters are escaped.

		@returns		TRUE if the operation succeeds - FALSE otherwise.
	*/
	static logical EscapeString( const String& input, String& output, unsigned long flags = PLMXML_ESCAPE_STANDARD );

	//!	Converts an escaped URI string to its unescaped representation.
	/*!
		This can be seen to be the reverse of the EscapeString function - in that
		unescaping a string that has previously been escaped (with the same options)
		will return the original string.

		Characters in the input string will be unescaped according to the value 
		of the 'flags' argument. This can be a bitwise combination of any of
		the following flags:

			PLMXML_ESCAPE_NONE

				No unescaping of the input URI string will occur.

			PLMXML_ESCAPE_SPACE		%20		as	' '
					
			PLMXML_ESCAPE_HASH		%23		as	'#'

			PLMXML_ESCAPE_PERCENT	%25		as	'%'

			PLMXML_ESCAPE_STANDARD	(DEFAULT)

				All supported characters are unescaped.

			PLMXML_ESCAPE_EXTENDED

				All escaped characters in the input URI string will be unescaped.

		For example if PLMXML_ESCAPE_STANDARD is specified:

		\verbatim
		"foo%20bar.txt"			->	"foo bar.txt"
		"foo%23bar.txt"			->	"foo#bar.txt"
		"foo%25bar.txt"			->	"foo%bar.txt"
		"foo%2520bar%20.txt"	->	"foo%20bar .txt"
		\endverbatim

		If PLMXML_ESCAPE_EXTENDED is specified:

		\verbatim
		"foo%23bar.plmxml#id7"								->	"foo#bar.plmxml#id7
		"foo.txt?date=2010%2f04%2f14;time=09%3a04%3a29"		->	"foo.txt?date=2010/04/14;time=09:04:29"
		\endverbatim

		@param	input	Input string to unescape.
		@param	output	Output unescaped string.
		@param	flags	Set of options to control which characters are unescaped.

		@returns		TRUE if the operation succeeds - FALSE otherwise.
	*/
	static logical UnescapeString( const String& input, String& output, unsigned long flags = PLMXML_ESCAPE_STANDARD );
};

//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//! PLMXML Toolkit Plugin type.
#define plmxmlPluginType			int

//! Unset Plugin type.
#define plmxmlPluginUnset			0

//! Adapter Plugin type.
#define plmxmlPluginAdapter         1

//! URIResolver Plugin type.
#define plmxmlPluginURIResolver     3

//////////////////////////////////////////////////////////////////////
// Plugin control - Plugin operation data and macros

class PluginProcessDataImpl;

//! PluginProcessData class
/*!
    PluginProcessData class encapsulates data required to invoke certain 
    functionality of a plugin.

    Applications are not expected to use this mechanism of calling plugin functionality directly.
    
    PLM XML toolkit will instantiate and pass a pointer to this class to plugins.

    Plugins may also invoke other plugins, in this case, particularly when developing a
    data adapter, the following macros should be used to construct a call to a plugin:

    \verbatim
        Result result;
        Configuration* config = ...
        String path = "c:/dir/file...";
        int mode = PLMXML_STREAM_READ;
        Stream* stream = NULL;

        URIResolverRef pResolver;
        PLMXML_PLUGIN_OP_DECLARE_DATA( PLMXML_OP_RESOLVER_RESOLVE_URI, config, &result )
            PLMXML_OP_SET_DATA( PLMXML_OP_DATA_MODE, &mode );
            PLMXML_OP_SET_DATA( PLMXML_OP_DATA_URI_STRING, &path );
            PLMXML_OP_SET_DATA( PLMXML_OP_DATA_STREAM_REF, &stream );
        PLMXML_PLUGIN_OP_EXEC( pResolver )

        if( stream != NULL )
            ...
    \endverbatim

    Data is returned from a plugin using pointers as demonstrated by 'stream' variable.

    In order to access the data when inside a plugin the following macros should be used:

    \verbatim
        void MyAdapter::Process( plmxml_api::PluginProcessData* data )
        {
            Result* result = NULL;
            PLMXML_OP_GET_DATA( data, PLMXML_OP_DATA_RESULT, result );

            if( data->op == PLMXML_OP_ADAPTER_DESTROY )
            {
                Array<Handle>* handles = NULL;
                PLMXML_OP_GET_DATA( data, PLMXML_OP_DATA_HANDLES, handles );

                for( int i=0; i<handles->GetSize(); i++ )
                    ...
            }
            else if( ....
                ...
            else
                result->AddError( ErrorCodeFailed, "Unknown operation ..." );
        }
    \endverbatim
*/
class PLMXML_API PluginProcessData
{
    PluginProcessDataImpl* m_pImpl;

public:
    //! operation code: PLMXML_OP_ADAPTER_IMPORT, PLMXML_OP_RESOLVER_RESOLVE_URI, etc.
    int op;

public:
    //! Default constructor
    PluginProcessData();

    //! Destructor
    ~PluginProcessData();

    //! Get data item identified by 'key'
    /*!
        PLMXML_OP_GET_DATA macro is recommended instead of direct call to this function

        \verbatim
        PluginProcessData* data = .....

        Result* result = NULL;
        PLMXML_OP_GET_DATA( data, PLMXML_OP_DATA_RESULT, result );
        \endverbatim
    */
    void Get( int key, PLMXML_MODELLER_HANDLE& value );

    //! Set data item identified by 'key'
    /*!
        PLMXML_OP_SET_DATA macro is recommended instead of direct call to this function

        \verbatim
        Result result;
        PLMXML_PLUGIN_OP_DECLARE_DATA( PLMXML_OP_RESOLVER_RESOLVE_URI )
            PLMXML_OP_SET_DATA( PLMXML_OP_DATA_RESULT, &result );
        PLMXML_PLUGIN_OP_EXEC( resolver )
        \endverbatim
    */
    void Set( int key, PLMXML_MODELLER_HANDLE value );
};

//////////////////////////////////////////////////////////////////////
/*! \defgroup PluginOpData Plugin operation data
*/

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_RESULT key, value of type 'plmxml_api::Result*', always present in all operations
*/
#define PLMXML_OP_DATA_RESULT           0
#define PLMXML_OP_DATA_RESULT_TYPE      plmxml_api::Result*

/*! \ingroup PluginOpData 
    PLMXML_OP_DATA_CONFIG key, value of type 'plmxml_api::Configuration*', always present in all operations
*/
#define PLMXML_OP_DATA_CONFIG           1
#define PLMXML_OP_DATA_CONFIG_TYPE      plmxml_api::Configuration*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_OBJECT key, value of type 'plmxml_api::Object*'
*/
#define PLMXML_OP_DATA_OBJECT           2
#define PLMXML_OP_DATA_OBJECT_TYPE      plmxml_api::Object*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_FIELD_NAME key, value of type 'char*'
*/
#define PLMXML_OP_DATA_FIELD_NAME       3
#define PLMXML_OP_DATA_FIELD_NAME_TYPE  char*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_POINTER key, value of type 'plmxml_api::Pointer*'
*/
#define PLMXML_OP_DATA_POINTER          4
#define PLMXML_OP_DATA_POINTER_TYPE     plmxml_api::Pointer*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_MODE key, value of type 'int*'
*/
#define PLMXML_OP_DATA_MODE             5
#define PLMXML_OP_DATA_MODE_TYPE        int*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_ACTION key, value of type 'int*'
*/
#define PLMXML_OP_DATA_ACTION           6
#define PLMXML_OP_DATA_ACTION_TYPE      int*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_STREAM_REF key, value of type 'plmxml_api::Stream**'
*/
#define PLMXML_OP_DATA_STREAM_REF       7
#define PLMXML_OP_DATA_STREAM_REF_TYPE  plmxml_api::Stream**

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_STREAM key, value of type 'plmxml_api::Stream*'
*/
#define PLMXML_OP_DATA_STREAM           8
#define PLMXML_OP_DATA_STREAM_TYPE      plmxml_api::Stream*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_URI_STRING key, value of type 'plmxml_api::String*'
*/
#define PLMXML_OP_DATA_URI_STRING       9
#define PLMXML_OP_DATA_URI_STRING_TYPE  plmxml_api::String*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_HANDLES key, value of type 'plmxml_api::Array<plmxml_api::Handle>*'
*/
#define PLMXML_OP_DATA_HANDLES          10
#define PLMXML_OP_DATA_HANDLES_TYPE     plmxml_api::Array<plmxml_api::Handle>*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_HANDLES2 key, value of type 'plmxml_api::Array<plmxml_api::Handle>*'
*/
#define PLMXML_OP_DATA_HANDLES2         11
#define PLMXML_OP_DATA_HANDLES2_TYPE    plmxml_api::Array<plmxml_api::Handle>*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_LOCATOR key, value of type 'plmxml_api::String*'
*/
#define PLMXML_OP_DATA_LOCATOR          12
#define PLMXML_OP_DATA_LOCATOR_TYPE     plmxml_api::String*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_USTRING key, value of type 'plmxml_api::String*'
*/
#define PLMXML_OP_DATA_USTRING          13
#define PLMXML_OP_DATA_USTRING_TYPE     plmxml_api::String*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_ATTRIB_NAME key, value of type 'plmxml_api::String*'
*/
#define PLMXML_OP_DATA_ATTRIB_NAMES     14
#define PLMXML_OP_DATA_ATTRIB_NAMES_TYPE plmxml_api::Array<plmxml_api::String>*

/*! \ingroup PluginOpData
    PLMXML_OP_DATA_ATTRIB_VALUE key, value of type 'plmxml_api::String*'
*/
#define PLMXML_OP_DATA_ATTRIB_VALUES    15
#define PLMXML_OP_DATA_ATTRIB_VALUES_TYPE plmxml_api::Array<plmxml_api::String>*

/*! \ingroup PluginOpData
	PLMXML_OP_DATA_ADAPTER key, value of type 'PLMXML_MODELLER_HANDLE'
*/
#define PLMXML_OP_DATA_ADAPTER			16
#define PLMXML_OP_DATA_ADAPTER_TYPE		plmxml_api::Adapter**

#define PLMXML_OP_DATA_MAX              16


//////////////////////////////////////////////////////////////////////
/*! \defgroup PluginOpResolver Resolver operations
    current operation codes:
    \verbatim
        PLMXML_OP_RESOLVER_TRANSLATE_REF
        PLMXML_OP_RESOLVER_PROCESS_REF
        PLMXML_OP_RESOLVER_RESOLVE_URI
    \endverbatim
*/

//  resolver reply
#define PLMXML_RESOLVER_ACTION_STOP         0
#define PLMXML_RESOLVER_ACTION_CONTINUE     1

//! Translate URI query
/*! \ingroup PluginOpResolver

    For example: location="PLMXML(ABC-doc/body1/XT-doc)"
    after loading to be able to resolve it later we must have:
        location="c:/path/file.abc#PLMXML(ABC-doc/body1/XT-doc)"

    PluginProcessData keys in use: (PLMXML_OP_DATA_RESULT is always present)
    \verbatim
        PLMXML_OP_DATA_OBJECT           - [INPUT],  element owning the reference, e.g. Representation*
        PLMXML_OP_DATA_FIELD_NAME       - [INPUT],  field name, e.g. "location"
        PLMXML_OP_DATA_POINTER          - [INPUT],  field value, e.g. "PLMXML(ABC-doc/body1/XT-doc)"
        PLMXML_OP_DATA_MODE             - [INPUT],  mode, currently TRUE for loading, FALSE for saving
        PLMXML_OP_DATA_ACTION           - [OUTPUT], resolver reply, 
                                                PLMXML_RESOLVER_ACTION_CONTINUE to translate,
                                                PLMXML_RESOLVER_ACTION_STOP to keep "PLMXML(ABC-doc/body1/XT-doc)"
    \endverbatim
*/
#define PLMXML_OP_RESOLVER_TRANSLATE_REF    1

//! Process URI query
/*! \ingroup PluginOpResolver
    Follows the PLMXML_OP_RESOLVER_TRANSLATE_REF operation, 
    whether to attempt resolving the reference.

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_OBJECT           - [INPUT],  element owning the reference
        PLMXML_OP_DATA_FIELD_NAME       - [INPUT],  field name of the reference
        PLMXML_OP_DATA_POINTER          - [INPUT],  translated field value, e.g. "c:\path\file.xpkPLMXML(XPK-doc/body1/XT-doc)"
        PLMXML_OP_DATA_MODE             - [INPUT],  mode, TRUE for loading, FALSE for saving
        PLMXML_OP_DATA_ACTION           - [OUTPUT], resolver reply, 
                                                PLMXML_RESOLVER_ACTION_CONTINUE to proceed with resolving,
                                                PLMXML_RESOLVER_ACTION_STOP not to resolve
    \endverbatim
*/
#define PLMXML_OP_RESOLVER_PROCESS_REF      2

//! Resolve URI operation
/*! \ingroup PluginOpResolver
    given URI and mode (read/write/etc.) create plmxml_api::Stream*

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_URI_STRING       - [INPUT],  pointer to uri string, e.g "c:/path/file.plmxml"
        PLMXML_OP_DATA_MODE             - [INPUT],  mode how to open, a combination of 
                                                PLMXML_STREAM_READ|PLMXML_STREAM_WRITE|PLMXML_STREAM_RANDOM_ACCESS, etc.
        PLMXML_OP_DATA_STREAM_REF       - [OUTPUT], opened stream, must be 'new' pointer. SDK will delete it.
    \endverbatim
*/
#define PLMXML_OP_RESOLVER_RESOLVE_URI      3


/*! \defgroup PluginOpAdapter Adapter operations
    current operation codes:
    \verbatim
        PLMXML_OP_ADAPTER_IMPORT 
        PLMXML_OP_ADAPTER_EXPORT 
        PLMXML_OP_ADAPTER_GET    
        PLMXML_OP_ADAPTER_LOAD   
        PLMXML_OP_ADAPTER_SAVE   
        PLMXML_OP_ADAPTER_LOCATE 
        PLMXML_OP_ADAPTER_DESTROY
        PLMXML_OP_ADAPTER_CLONE
        PLMXML_OP_ADAPTER_INITIALISE
        PLMXML_OP_ADAPTER_TERMINATE
    \endverbatim
*/

//! adapter PLMXML_OP_ADAPTER_GET operation mode (start from 16th bit)
#define PLMXML_ADAPTER_GET_MODE_STREAM      (1<<16)
//! adapter PLMXML_OP_ADAPTER_GET operation mode (start from 16th bit)
#define PLMXML_ADAPTER_GET_MODE_HANDLE      (1<<17)

//! Import from a format
/*! \ingroup PluginOpAdapter
    translation from a format to PLM XML run-time model

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_HANDLES          - [OUTPUT], created PLM XML top-level objects 
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_IMPORT            1

//! export to a format
/*! \ingroup PluginOpAdapter
    Translate PLM XML Object* trees into a "format".

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_HANDLES          - [INPUT], top-level PLM XML object to output
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_EXPORT            2

//! Extract a resource from a format
/*! \ingroup PluginOpAdapter
    Resource can be a stream or a handle of format's run-time structure.

    Adapters form a chain when resolving a reference. An instance of adapter in
    the chain has pointers to the previous and next adapters.

    Resource is identified by next adapter's context. This context may be modified
    by the adapter, for example to reflect the actual location where the data is saved.

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_MODE             - [INPUT],  indicates to the adapter that the resource should be returned as 
                                                    a stream - PLMXML_ADAPTER_GET_MODE_STREAM
                                                    or a handle - PLMXML_ADAPTER_GET_MODE_HANDLE
                                                    or either.

                                                    if a stream is required then mode also contains a combination of
                                                    PLMXML_STREAM_READ, PLMXML_STREAM_WRITE, PLMXML_STREAM_RANDOM_ACCESS, etc.

        PLMXML_OP_DATA_STREAM_REF       - [OUTPUT], opened stream, must be 'new' pointer. SDK will delete it.
        PLMXML_OP_DATA_HANDLES          - [OUTPUT], format's handles can be returned instead of the stream if
                                                    mode & PLMXML_ADAPTER_GET_MODE_HANDLE.
    \endverbatim

*/
#define PLMXML_OP_ADAPTER_GET               3

//! Load format's native data.
/*! \ingroup PluginOpAdapter
    Load this format's native data into memory and return array of handles to it.

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_HANDLES          - [OUTPUT], loaded handles
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_LOAD              4

//! Save format's native data.
/*! \ingroup PluginOpAdapter
    Save this format's native data.

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_HANDLES          - [INPUT], handles to save
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_SAVE              5

//! Identifies a collection of entities in the given array of handles 
/*! \ingroup PluginOpAdapter
    PLMXML_OP_DATA_LOCATOR specifies how the selection should be made.

    if PLMXML_OP_DATA_LOCATOR value is NULL or an empty string then 
    PLMXML_OP_DATA_HANDLES contain NOT top-level objects and the adapter 
    is expected to RETURN relevant top-level objects in PLMXML_OP_DATA_HANDLES2.

    For example Document* will be returned by the PLMXML adapter if
    PLMXML_OP_DATA_HANDLES contained Part*, etc.

    if PLMXML_OP_DATA_LOCATOR is a valid string then PLMXML_OP_DATA_HANDLES
    contain top-level entities and the adapter is expected to make a 
    selection of sub-objects according to PLMXML_OP_DATA_LOCATOR and 
    return them in PLMXML_OP_DATA_HANDLES2.

    For example given an array of XT body tags and 
    "body[@name='main']/face[@id='23']" control string would cause XT adapter
    to return a single face tag.

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_HANDLES          - [INPUT],  handles to examine
        PLMXML_OP_DATA_LOCATOR          - [INPUT],  selection string
        PLMXML_OP_DATA_HANDLES2         - [OUTPUT], selected entities
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_LOCATE            6

//! Delete this format's handles
/*! \ingroup PluginOpAdapter
    Handles in the input PLMXML_OP_DATA_HANDLES array need to be destroyed as a result
    of, for example, Document* they attached to, being deleted.

    PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_HANDLES          - [INPUT], array of handles to be deleted
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_DESTROY           7

//! Reset the adapter
/*!	\ingroup PluginOpAdapter
	Deprecated. This operation will no longer be requested.
*/
#define PLMXML_OP_ADAPTER_RESET				8

//! Clones the adapter
/*! \ingroup PluginOpAdapter
	PLMXML_OP_ADAPTER_CLONE specifies that the adapter return a new instance of itself. 

	PluginProcessData keys in use:
    \verbatim
        PLMXML_OP_DATA_ADAPTER_TYPE          - [OUTPUT], New instance of Adapter
    \endverbatim
*/
#define PLMXML_OP_ADAPTER_CLONE				9

//! Initialises an adapter
/*! \ingroup PluginOpAdapter
    PLMXML_OP_ADAPTER_INITIALISE provides an adapter the oppotunity to 
    carry out any initialise actions it requires. It will be called by
    Initialise function on any adapters it loads.
*/
#define PLMXML_OP_ADAPTER_INITIALISE        10
//! Terminates an adapter
/*! \ingroup PluginOpAdapter
    PLMXML_OP_ADAPTER_TERMINATE provides an adapter the oppotunity to
    carry out any termination actions it requires. It will be called by
    the Terminate function on any adapters loaded via the Initialise function.
*/
#define PLMXML_OP_ADAPTER_TERMINATE         11

//////////////////////////////////////////////////////////////////////
class PluginDescriptor;
class Configuration;
//////////////////////////////////////////////////////////////////////
//! Internal
typedef void* (*PLMXML_FN_GET_PLUGIN_INSTANCE)( void );
//! Internal
typedef void  (*PLMXML_FN_GET_PLUGIN_PROPERTIES)( PluginDescriptor*, Configuration* );

//////////////////////////////////////////////////////////////////////
//! Class PluginDescriptorCallback
/*!
	Base class that defines a callback function that is used to load a 
	plugin at runtime. This is called by the framework if it unable to 
	find a plugin of the required type.
*/
class PLMXML_API PluginDescriptorCallback
{
public:
	// !Constructor
    PluginDescriptorCallback();
    
	// !Destructor
	virtual ~PluginDescriptorCallback();

	//! This function is called by the framework if it unable to find a plugin of the required type
	virtual logical operator( ) ( const plmxmlPluginType& type, const String& strName ) = 0; 
};

class PluginDescriptorImpl;

//////////////////////////////////////////////////////////////////////
//! Class PluginDescriptor
/*!
	The PluginDescriptor class represents an entry in loaded plugins registry.
*/
class PLMXML_API PluginDescriptor
{
public:
    
    //! Get plugin descriptor type
    plmxmlPluginType GetType( void ) const;

	//! Sets the type of the plugin
	void SetType( plmxmlPluginType type );

    //! Get plugin descriptor name
    const String& GetName( void ) const;

	//! Sets the name of the plugin
	void SetName( const String& name );

	//! Gets the base plugin
	PluginDescriptor* GetBase( ) const;

	//! Sets the base plugin
	void SetBase( PluginDescriptor* pDescriptor );

	//! Sets the instance function
	void SetInstanceFunction( PLMXML_FN_GET_PLUGIN_INSTANCE instanceFn );

	//! Removes if present the specified plugin instance
	void RemoveInstance( void* instance );

	//! Sets the properties function
	void SetPropertiesFunction( PLMXML_FN_GET_PLUGIN_PROPERTIES propertiesFn );

    //! Set properties associated with this plugin as plmxml_api::Configiration
    void GetProperties( Configuration& properties ) const;

    //! Enumerate all loaded plugin descriptors
    static void  GetDescriptors( Array<PluginDescriptor*>& descriptors );

    //! Enumerate loaded plugin descriptors of the given 'type'
    static void  GetDescriptors( const plmxmlPluginType& type, Array<PluginDescriptor*>& descriptors );

	//! Get an instance of a plugin of the given 'type'
    static void* GetInstance( const plmxmlPluginType& type );

	//! Get an instance of a plugin with the given 'type' and 'name'
    static void* GetInstance( const plmxmlPluginType& type, const String& name );

	//! Register a callback to be used if no plugin of the requested type can be found
	/*!
		The callback must be a class derived from PluginDescriptorCallback that 
		implements the operator function. This callback will be used if the framework
		is unable to find a plugin that matches both 'type' and 'name'. It is then up to 
		the application to load the requested plugin - if this succeeds it should return
		TRUE.
	*/
	static void RegisterCallback( PluginDescriptorCallback* pCallback );

	//! Internal Function
	PluginDescriptorImpl* GetImplementation( ) const;

private:

	friend class PluginDescriptorImpl;

	// !Constructor
    PluginDescriptor( );

	//! Destructor
	virtual ~PluginDescriptor( );

	//! Internal field
	PluginDescriptorImpl*		m_pImpl;
};

//////////////////////////////////////////////////////////////////////

/*! \defgroup PluginMacros Plugin Helper Macros
    A series of helper macros that are used to both define and manipulate 
	macros. The following macros are supported:
    \verbatim
		PLMXML_DECLARE_PLUGIN					Declares a new Plugin class.
		PLMXML_DEFINE_PLUGIN_BEGIN				Defines the start of the Plugin implementation.
		PLMXML_DEFINE_PLUGIN_CR_DEFAULT			Defines the start of the Plugin constructor.
		PLMXML_DEFINE_PLUGIN_DR					Defines the start of the Plugin destructor.
		PLMXML_DEFINE_PLUGIN_PROPERTY			Defines a specific property for the Plugin.
		PLMXML_DEFINE_PLUGIN_VERSION			Defines a version for the Plugin.
		PLMXML_DEFINE_PLUGIN_GET_PROPERTIES		Defines a function to get the properties of the Plugin.
		PLMXML_DEFINE_PLUGIN_GET_INSTANCE		Defines a function to get an instance of the Plugin.
		PLMXML_DEFINE_PLUGIN_END				Defines the end of the Plugin definition code.
    \endverbatim
*/

//! Declares a new Plugin class.
/*! \ingroup PluginMacros
    Arguments:
    \verbatim
        type	- Type of the Plugin. May be one of:
					Adapter
					URIResolver.
		name	- Name of the Plugin class.
		base	- Base class for the Plugin. This must be consistent
				  with the type of the plugin:
					Adapter			- plmxml_api::Adapter		(or derived class)
					URIResolver		- plmxml_api::URIResolver	(or derived class)
    \endverbatim
*/
#define PLMXML_DECLARE_PLUGIN( type, name, base ) \
public: \
	static plmxml_api::PluginDescriptor* m_Plugin##name; \
public: \
    name(); \
    virtual ~name(); \
public: \
	virtual plmxml_api::PluginDescriptor *GetPluginDescriptor() const; \
	static plmxml_api::PluginDescriptor *GetStaticPluginDescriptor();

//! Defines the start of the Plugin implementation.
/*! \ingroup PluginMacros
    Arguments:
    \verbatim
        type	- Type of the Plugin. May be one of:
					Adapter
					URIResolver
		name	- Name of the Plugin class.
		base	- Base class for the Plugin.
		format	- Format string of the plugin ("ABC").
    \endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_BEGIN( type, name, base, format ) \
	static void* __##name##_MakeInstance( ); \
    static void  __##name##_GetProperties( plmxml_api::PluginDescriptor*, plmxml_api::Configuration* ); \
	static plmxml_api::logical	__##name##_RegisterPlugin( void* cd ) \
	{ \
		plmxml_api::PluginDescriptor* pDescriptor = (plmxml_api::PluginDescriptor*)cd; \
		if ( pDescriptor == NULL ) \
			return FALSE; \
        \
	    pDescriptor->SetType( plmxmlPlugin##type ); \
	    pDescriptor->SetName( format ); \
	    pDescriptor->SetBase( base::GetStaticPluginDescriptor() ); \
	    pDescriptor->SetInstanceFunction( __##name##_MakeInstance ); \
	    pDescriptor->SetPropertiesFunction( __##name##_GetProperties ); \
        \
		name::m_Plugin##name = pDescriptor; \
	    return TRUE; \
    } \
	static plmxml_api::LinkNode	__##name##_LinkNode( __##name##_RegisterPlugin, plmxmlLinkTypePlugin ); \
	plmxml_api::PluginDescriptor* name::m_Plugin##name = NULL; \
	plmxml_api::PluginDescriptor* name::GetPluginDescriptor() const \
	{ \
	return m_Plugin##name; \
	} \
	plmxml_api::PluginDescriptor* name::GetStaticPluginDescriptor( ) \
	{ \
	return m_Plugin##name; \
	}

//! Defines the start of the Plugin constructor.
/*! \ingroup PluginMacros
	Any initialisation code for the Plugin can be placed
	immediately after a call to this macro.
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_CR_DEFAULT( name ) \
    name::name() \
    {

//! Defines the start of the Plugin destructor.
/*! \ingroup PluginMacros
	Any cleanup code for the Plugin can be placed
	immediately after a call to this macro.
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_DR( name ) \
    } \
    name::~name() \
    { \
	name::m_Plugin##name->RemoveInstance( (void*)this );

//! Defines a specific property for the Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		key		- The property value name.
		value	- The property value.
    \endverbatim

	The following common plugin properties are currently supported:
	\verbatim
		"FILE_EXTENSIONS"	- Semi-colon separated list of the file extensions
							that the adapter supports ("plmxml;xml").
		"DESCRIPTION"		- Description of the Plugin.
		"FORMAT"			- Only valid for adapters. Specifies the format of 
							the adapter ("ABC").
	\endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_PROPERTY( key, value ) \
    pConfiguration->Set( key, value );

//! Defines a version for the Plugin.
/*! \ingroup PluginMacros
	The version of the Plugin is defined by the string value of the
    \verbatim
		VERSION_INFO_IDENT_STRING 
	\endverbatim
	preprocessor definition.
*/
#ifdef VERSION_INFO_IDENT_STRING
#define PLMXML_DEFINE_PLUGIN_VERSION PLMXML_DEFINE_PLUGIN_PROPERTY( "VERSION", VERSION_INFO_IDENT_STRING )
#else
#define PLMXML_DEFINE_PLUGIN_VERSION
#endif

//! Defines a function to get the properties of the Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_GET_PROPERTIES( name ) \
    } \
	void __##name##_GetProperties( plmxml_api::PluginDescriptor* pPluginDescriptor, plmxml_api::Configuration* pConfiguration ) \
	{ \
        PLMXML_DEFINE_PLUGIN_VERSION

//! Defines a function to get an instance of the Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
	Code placed immediately after this macros must set an 
	instance of the plugin in the following way:

	\verbatim
		theInstance = new MDB;
	\endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_GET_INSTANCE( name ) \
	} \
	void* __##name##_MakeInstance( void ) \
	{ \
		name* theInstance = NULL;

//! Defines the end of the Plugin definition code.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_END( name ) \
	    return theInstance; \
    }

///////////////////////////////////////////////

#define PLMXML_DECLARE_PLUGIN_INTERNAL( name ) \
public: \
    static plmxml_api::PluginDescriptor* m_Plugin; \
	virtual plmxml_api::PluginDescriptor* GetPluginDescriptor() const; \
	static plmxml_api::PluginDescriptor* GetStaticPluginDescriptor();

#define PLMXML_DEFINE_PLUGIN_INTERNAL( type, name ) \
	static plmxml_api::logical	__##name##_RegisterPlugin( void* cd ) \
    { \
	    plmxml_api::PluginDescriptor* pDescriptor = (plmxml_api::PluginDescriptor*)cd; \
	    if ( pDescriptor == NULL ) \
		    return FALSE; \
        \
	    pDescriptor->SetType( plmxmlPlugin##type ); \
	    name::m_Plugin = pDescriptor; \
	    return TRUE; \
    } \
	static plmxml_api::LinkNode	__##name##_LinkNode( __##name##_RegisterPlugin, plmxmlLinkTypePlugin ); \
	plmxml_api::PluginDescriptor* name::m_Plugin = NULL; \
	plmxml_api::PluginDescriptor* name::GetPluginDescriptor() const \
	{ \
		return m_Plugin; \
	} \
	plmxml_api::PluginDescriptor* name::GetStaticPluginDescriptor() \
	{ \
	return m_Plugin; \
	}

//! Declares the entry point for the Process function for the Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
*/
#define PLMXML_DECLARE_PLUGIN_PROC( name ) \
    void Process( plmxml_api::PluginProcessData* data );

//! Defines the entry point for the Process function for the Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		name	- Name of the Plugin class.
    \endverbatim
*/
#define PLMXML_DEFINE_PLUGIN_PROC( name ) \
    void name::Process( plmxml_api::PluginProcessData* data )

//! Sets the data for a particular Plugin operation.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		data_code	- Identifier for the type of data to associate with the operation.
					May be one of the Plugin operation data codes.

		data_value	- Value of the data for the operation.
    \endverbatim
	
	This macro must only be used within a pair of matching 
	\verbatim
		PLMXML_PLUGIN_OP_DECLARE_DATA/PLMXML_PLUGIN_OP_EXEC
	\endverbatim
	macros.
*/
#define PLMXML_OP_SET_DATA( data_code, data_value ) \
		__ppd.Set( data_code, (plmxml_api::PLMXML_MODELLER_HANDLE)data_value ); \

//! Gets the data for a particular Plugin operation.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		data_ptr	- Instance of a plmxml_api::PluginProcessData class that contains
					the data for the operation.
		data_code	- Identifier for the type of data to associate with the operation.
					May be one of the Plugin operation data codes.
		data_value	- Value of the data for the operation.
    \endverbatim
*/
#define PLMXML_OP_GET_DATA( data_ptr, data_code, data_value ) \
    { \
		plmxml_api::PLMXML_MODELLER_HANDLE __val = 0; \
        data_ptr->Get( data_code, __val ); \
        data_value = (data_code##_TYPE)__val; \
    }

//! Declares the start of a call to a Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		cmd		- Operation code for the Plugin. The code must be valid 
				for the adapter.
		cfg		- Optional options for the operation (plmxml_api::Configuration*).
		res		- Result of the operation (plmxml_api::Result*)
    \endverbatim
	
	This macro must only be matched by a following
	\verbatim
		PLMXML_PLUGIN_OP_EXEC
	\endverbatim
	macro.
*/
#define PLMXML_PLUGIN_OP_DECLARE_DATA( cmd, cfg, res ) \
    { \
        plmxml_api::PluginProcessData __ppd; __ppd.op = cmd;\
        PLMXML_OP_SET_DATA( PLMXML_OP_DATA_RESULT, res ) \
        PLMXML_OP_SET_DATA( PLMXML_OP_DATA_CONFIG, cfg )
        
//! Declares the end of a call to a Plugin.
/*! \ingroup PluginMacros
	Arguments:
    \verbatim
		plugin	- Instance of a Plugin to execute the previously set 
				operation on.
    \endverbatim
	
	This macro must follow a previous matching call to a
	\verbatim
		PLMXML_PLUGIN_OP_DECLARE_DATA
	\endverbatim
	macro.
*/
#define PLMXML_PLUGIN_OP_EXEC( plugin ) \
        plugin->Process( &__ppd ); \
    }

//////////////////////////////////////////////////////////////////////

class ParserImpl;

//////////////////////////////////////////////////////////////////////
// <tag> names and attribute names are "char*"
// attribute values and element content are "UChar*"
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//! Abstract XML Parser class
/*! 
    Application is expected to provide implementation of this class for 
    a specific parser.

    Refer to Xerces and MS implementations in this SDK.
*/
class PLMXML_API Parser : public Allocator
{
    PLMXML_DECLARE_PLUGIN_INTERNAL( Parser )

    ParserImpl* m_pImpl;

public:
    //! Constructor
    Parser();

	//! Destructor
	virtual ~Parser();

	//! Internal function
	ParserImpl* GetImplementation( ) const;

    //! Override in derived classed to implement specific processing
    virtual void Process( PluginProcessData* data );
};

//////////////////////////////////////////////////////////////////////

class URIResolverImpl;
class URIResolverRefImpl;

//////////////////////////////////////////////////////////////////////
//! URIResolver class
/*! 
    This is a Plug-in for converting URIs to PLMXML streams.
*/
class PLMXML_API URIResolver : public Allocator
{
    URIResolverImpl*    m_pImpl;

    PLMXML_DECLARE_PLUGIN_INTERNAL( URIResolver )

public:
    //! Default constructor
	URIResolver();  

    //! Destructor
	virtual ~URIResolver();

    virtual void Process( PluginProcessData* data );

	//! Converts a URI to a Stream, for load or save

    //! Controls whether an attempt is made to resolve and load or save referenced external resources.
    /*!
        Application may override this function to control whether external references
        are loaded or saved.

        Built-in version always returns TRUE.

        'read' argument is TRUE for loading and FALSE for saving.
        'fieldName' argument represents an attribute name being resolved of the 'owner' object.
    */

	//! Register Object & Pointer in resolver's map
	virtual Result RegisterObject( 
        const Handle& hObject,
		const Pointer& ptr );

	//! Determines whether any Objects exists in the map, for a given Pointer
	virtual logical FindObjects( 
		const Pointer& ptr,
        Array<Handle>& objects );

	//! Determines whether an Pointer exists in the map, for a given Object
	virtual logical FindPointer( 
        const Handle& hObject,
		Pointer& ptr );

    //! Replace object in the map, return FALSE if 'oldObj' cannot be found.
    virtual logical ReplaceObject( 
        const Handle& oldObj, 
        const Handle& newObj );

////////////////////////////////////////////////////////////////////////////////
//! Deregisters a handle to an object from the resolver's map
/*!
	DeregisterObject removes a handle to an object from the URIResolver map.
	
	If the Handle is in the map and the corresponding Pointer only points to 
	the Handle being removed then both the Handle and Pointer are removed from the map.

	If the Handle is in the map but the corresponding Pointer points to multiple Handles
	Then the Handle will be removed from the map, the pointer is left in the map and if 
	necessary its registered handle value changed to an alternative Handle.

	If the Handle is not present in the map the function will just return with an empty Result.
    
	@param hObject The Handle we want removed from the URIResolver map
	@returns A Result object indicating the success or failure of the operation, failure 
		returns ErrorCodeFailed.
*/
	Result DeregisterObject(
		const Handle& hObject );
};

//////////////////////////////////////////////////////////////////////

// URIDefaultResolver class removed
#define URIDefaultResolver URIResolver

//////////////////////////////////////////////////////////////////////
//! URIResolverRef class
/*! 
    Wrapper around calls to get and delete an instance of a URI resolver.
*/
class PLMXML_API URIResolverRef : public Allocator
{
    URIResolverRefImpl* m_pImpl;

public:
    //! Constructor
    /*!
        'activeResolver' parameter can be given to specify an instance
        of URIResolver to be used by the toolkit while this 
        instance of URIResolverRef is in scope.
    */
    URIResolverRef( URIResolver* activeResolver=NULL );

    //! Destructor
    ~URIResolverRef();

    //! Access to stored URIResolver*
    URIResolver* operator->();
};

//////////////////////////////////////////////////////////////////////

class Query;
class AdapterImpl;

//////////////////////////////////////////////////////////////////////
//! Adapter class
/*!
The base class for Data Adapter classes.

Adapter instances are created when SDK is resolving references or 
importing/exporting PLMXML from/to native format.

An instance of the adapter has associated format, context string and 
previous and next adapter pointers. 

Adapter format is a "fixed" property initialised when adapter is 
loaded into memory and cannot be changed at run-time. 

Adapter context is specific to current operation, e.g. filename 
of the reference being resolved.

The process of resolving a reference involves creation of more than 
one adapter instances. Adapter instances are connected to each other 
in a form of chain, thus each adapter has previous and next adapters.

For example:

Resolving the following \#PLMXML pointer reference:

    <LocatorRef ... 
        locationRef="scheme://host:port/path/file.aaa\#PLMXML(AAA-doc/xxxxx/BBB-doc/yyyyy/XT-doc/locator)" />

a chain of adapters is created:

    system - AAA - BBB - XT

where 'system' is a built-in adapter type without a format which handles opening of files.

\verbatim
             previous  next     context

    system   NULL      AAA      scheme://host:port/path
    AAA      system    BBB      file.aaa
    BBB      AAA       XT       xxxxxx
    XT       BBB       NULL     locator

    Processing of the chain starts from the end, 
    XT adapter asks BBB for "yyyyy" stream, 
    BBB requests "xxxxx" from AAA,
    AAA contacts 'system' for file.aaa
    system opens "scheme://host:port/path/file.aaa" as Stream
    using URIResolver.
\endverbatim

Typical data adapter should initialise its properties as shown below.

\verbatim
#include <version.ver>

PLMXML_BEGIN_NAMESPACE( plmxml_adapter )
PLMXML_BUILD_INFO_IDENT

//////////////////////////////////////////////////////////////////////

PLMXML_DEFINE_PLUGIN_BEGIN( Adapter, XT, Adapter, "XT" )
PLMXML_DEFINE_PLUGIN_CR_DEFAULT( XT )
PLMXML_DEFINE_PLUGIN_DR( XT )
PLMXML_DEFINE_PLUGIN_GET_PROPERTIES( XT )

    PLMXML_DEFINE_PLUGIN_PROPERTY( "FORMAT", "XT" )
    PLMXML_DEFINE_PLUGIN_PROPERTY( "DESCRIPTION", "Parasolid Format" )
    PLMXML_DEFINE_PLUGIN_PROPERTY( "FILE_EXTENSIONS", "xmt_txt;x_t;xmt_bin;x_b" )

PLMXML_DEFINE_PLUGIN_GET_INSTANCE( XT )

    theInstance = new XT;

PLMXML_DEFINE_PLUGIN_END( XT )

\endverbatim
*/
class PLMXML_API Adapter : public Allocator
{
public:
    AdapterImpl*    m_pImpl;

protected:
    PLMXML_DECLARE_PLUGIN_INTERNAL( Adapter )

public:
	//! Constructor
	Adapter();

	//! Destructor
	virtual ~Adapter();

    //! Get previous (parent) adapter in the chain
    Adapter* GetPrevious( void ) const;

    //! Set previous (parent) adapter in the chain
    void SetPrevious( Adapter* a );

    //! Get next adapter in the chain
    Adapter* GetNext( void ) const;

    //! Set next adapter in the chain
    void SetNext( Adapter* a );

    //! Get adapter context
    const String& GetContext( void ) const;

    //! Set adapter context
    void SetContext( const String& context );

    //! Get adapter format
    const String& GetFormat( void ) const;

    //! Reconstruct \#PLMXML Pointer from the chain ending with 'this' adapter.
    void ConstructPointer( Pointer& ptr ) const;

    //! Override in derived classed to implement specific processing
    virtual void Process( PluginProcessData* data );
};

//////////////////////////////////////////////////////////////////////

class AdapterRefImpl;

//! AdapterRef class
/*!
    AdapterRef is a convenience class to simplify creation and destruction
    of adapter chains.

    Used internally and in development of other adapters.

    For example import XPK file:

    XPK adapter handles PLMXML_OP_ADAPTER_IMPORT operation having the following chain:
    "system - XPK", where XPK has context "myfile.xpk". Since main PLMXML 
    stream is stored as "RootDef", XPK adapter needs an instance of PLMXML 
    adapter to process it, thus:
    
    AdapterRef xml( Pointer("#PLMXML(XPK-doc/RootDef/PLMXML-doc)"), this );
*/
class PLMXML_API AdapterRef : public Allocator
{
    AdapterRefImpl* m_pImpl;

public:
    //! Constructor. Create an adapter chain based on 'ptr' and attach it to 'parent'
    AdapterRef( const Pointer& ptr, Adapter* parent=NULL );

    //! Constructor. Create 'format's adapter instance and attach it to 'parent'
    AdapterRef( const String& format, Adapter* parent=NULL );

    //! Destructor. Adapter instances in the chain attached to 'parent' are deleted.
    ~AdapterRef();

    //! Access to stored Adapter*
    Adapter* operator->();

	//! Access to stored Adapter*
	Adapter* GetAdapter( ) const;

    //! Check if chain construction succeeded
    logical IsValid( void ) const;

    //! Adapter chain construction errors
    const Result& GetResult() const;
};

//////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////

#define PLMXML_Object_FIELDS( action )

class ClassDescriptor;
class TraverseContext;
class ClassData;
class Configuration;

extern PLMXML_API plmxmlClass plmxmlClassObject;

///////////////////////////////////////////////////////////////////////////////////

#define PLMXML_COPY_OBJECT   0
#define PLMXML_COPY_GENERIC (1<<1)
#define PLMXML_COPY_DEEP	(1<<2)
#define PLMXML_COPY_DEFAULT	(PLMXML_COPY_OBJECT|PLMXML_COPY_DEEP)

///////////////////////////////////////////////////////////////////////////////////

#define PLMXML_ADDREF_NO_CHECK			0
#define PLMXML_ADDREF_CHECK_EXISTING	(1<<1)
#define PLMXML_ADDREF_DEFAULT			PLMXML_ADDREF_NO_CHECK

///////////////////////////////////////////////////////////////////////////////////
//! Object class - base class for all plmxml elements
/*!
This is the base class for all classes representing types of XML elements
in an PLM XML file
*/
class PLMXML_API Object : public Allocator
{
public:

	friend class ClassData;

protected:
    //@{
	//! Internal functions.
	Object( );
	//@}

public:
    
	//! Destructor
	virtual ~Object();

	//! Returns the ClassDescriptor associated with this object
	ClassDescriptor* GetClassDescriptor( ) const;

	//! Returns true if the object may have a Description sub-element
	logical DescriptionOwner() const;
	
	//! Returns true if the object may have a Bound sub-element
	logical BoundOwner() const;
	
	//! Returns true if the object may have an Attribute sub-element
	logical AttributesOwner() const;
	
	//! Returns the class of the object
	plmxmlClass Is( void ) const;

	//! Returns true if the object is of the given concrete class
	logical Is( const plmxmlClass& Class ) const;

	//! Returns true if the object is of the given concrete class
	/*!
		'Class' can be qualified with a namespace in the form:

		\<namespace\>:\<class\>		(for example "http://www.plmxml.org/Schemas/PLMXMLSchema:Part")

		or unqualified. If unqualified then the class is assumed to be in the
		default PLM XML namespace.
	*/
	logical Is( const String& Class ) const;

	//! Returns true if the object class is a subclass of the given class
	logical IsSubClass( const plmxmlClass& Class ) const;

	//! Returns true if the object class is a subclass of the given class
	/*!
		'Class' can be qualified with a namespace in the form:

		\<namespace\>:\<class\>			(for example "http://www.plmxml.org/Schemas/PLMXMLSchema:Part")

		or unqualified. If unqualified then the class is assumed to be in the
		default PLM XML namespace.
	*/
	logical IsSubClass( const String& Class ) const;

	//! Return the name of the object class.
	const String& GetClassName( void ) const;

	//! Returns a string description of the given class
	static const String& GetClassName( const plmxmlClass& classType );

	//! Checks the consistency of the object.
    /*!
        @param    options   Options to control the behaviour of the validation.
                            If this is a NULL pointer then the default validation options
                            will be used.

        @returns            The result of the operation.
                            
        The following validation options are supported:
                            
        \verbatim
        validation
            type_checking    - specifies whether reference type-checking is
                            performed. The type of an IDREF or URI reference
                            can be specified in the schema by using the "plm:refType"
                            attribute. 
                            
                            Allowed Values:

                                "on"    Type-checking is performed. (Default)
                                
                                "off"    Type-checking it is not performed.
        \endverbatim
    */
    Result Validate( Configuration* options ) const;

	//! Checks the consistency of the object.
	/*!
		This version of the Validate function will use any default validation options and
		is equivalent to calling:

				Result Object::Validate( NULL )

		@returns		The result of the operation.
	*/
	Result Validate( void ) const;

	//! Get the description of the object, or "" if there is no description
	String GetObjectDescription( void ) const;

	//! Sets the object description
	logical SetObjectDescription( const String& u );

	//! Gets the User Pointer of the object
	/*!
	The User Pointer is simply a void* pointer which the application can
	use for any purpose it requires. It is not modified by the toolkit.
	*/
	void* GetUserPointer( void ) const;
	
	//! Set the User Pointer
	void SetUserPointer( void *pUserPointer );

	//! Get the ancestor with no parent, i.e. the root of the tree
    Object *GetRoot() const;

	//! Get the nearest Document object above this object
	/*!
	If there is no Document object above this object, return NULL
	*/
	Object* GetDocument( void ) const;

	//! Get the nearest DocumentBase object above this object
	/*!
	If there is no DocumentBase object above this object, return NULL
	*/
	Object* GetDocumentBase( void ) const;

	//! Get the top-level Document object
	/*!
	If the top-level object (the ancestor with no owner) of this object
	is not a Document, return NULL.
	*/
	Object* GetDocumentRoot( void ) const;

	//! Get the top-level DocumentBase object
	/*!
	If the top-level object (the ancestor with no owner) of this object
	is not a DocumentBase, return NULL.
	*/
	Object* GetDocumentBaseRoot( void ) const;

	//! Return the owner of this object in the element hierarchy.
	Object* GetOwner( void ) const;

    //! Get the Id associated with this Object. 
	/*! 
	If this is not derived from IdObject then the returned Id will be a
	a NULL id - ie. Id.IsNull = TRUE
	*/	
    String GetId( void ) const;

	//! Set the id of this object.
	/*!
	Note that this simply changes the id of the object, references (IDREF) to
	the object may be invalidated by this change. Returns FALSE if the id already
	exists in the element tree of this object. Does nothing if this Object is not
	derived from IdObject.
	*/
	logical SetId( const String& id );

	//! Set owner (parent) of this Object
	/*!
	This function can be used to join together two trees of Objects. 

	If this Object has a Null id, it will be allocated one of the form id<integer>.

	If there are objects in the trees with the same id, the function will fail, unless
	the ids were allocated by the SDK; in which case the id in the child tree will
	be replaced by a new one, and all references to it from within the child tree will
	be updated, whether IDREF or URI (i.e. of the form "#id123").

	The child object will be added to the first suitable field of the parent, unless
	'field' is used to specify a particular field. Suitable means that the class of the
	field is a base class of the class of the child, and that the field is not an 
	already-occupied single element field.
	*/
	Result SetOwner( Object *pParent, const String& field );

	//! Set owner (parent) of this Object
	/*!
	This function can be used to join together two trees of Objects. 

	If this Object has a Null id, it will be allocated one of the form id<integer>.

	If there are objects in the trees with the same id, the function will fail, unless
	the ids were allocated by the SDK; in which case the id in the child tree will
	be replaced by a new one, and all references to it from within the child tree will
	be updated, whether IDREF or URI (i.e. of the form "#id123").

	The child object will be added to the first suitable field of the parent. Suitable 
	means that the class of the field is a base class of the class of the child, and 
	that the field is not an already-occupied single element field.
	*/
	Result SetOwner( Object *pParent );

public:
	//! Traverse the object and its descendents
	/*!
To use the Traverse function, you define a subclass of TraverseContext, for
example:

\code
class TraverseContextCount : public TraverseContext
{
public:
    TraverseContextCount() { nCount = 0; }
    ~TraverseContextCount() {}

    plmxmlTraverseResult Visit( Object *pObject );

    int nCount;
};

plmxmlTraverseResult TraverseContextCount::Visit( Object *pObject )
{
    nCount++;
    return plmxmlTraverseContinue;
}

\endcode

To call it you go...


\code
    TraverseContextCount *pContext = new TraverseContextCount;

    Object *pObject;
    pplmxml->Traverse( pContext );

    printf( "Count = %d", pContext->nCount );
    delete pContext;
\endcode

The visit function returns plmxmlTraverseContinue to continue the traverse, 
plmxmlTraverseAbortLocal to continue the traverse but without visiting any of the children
of the current object, and it returns plmxmlTraverseAbort to abandon the traverse.

Note: Object::Traverse only returns Abort or Continue, not AbortLocal.
*/
	plmxmlTraverseResult Traverse( TraverseContext *pContext );

	//@{
	//! Generic field access functionality

	//! Whether the field 'name' is present 
	/*!
		The 'type' argument can be used to control which type of fields to check. This may be one of:

		PLMXML_FIELD_ATTRIBUTE		check for attribute fields
		PLMXML_FIELD_ELEMENT		check for element fields
		PLMXML_FIELD_CONTENT		check for content fields
		PLMXML_FIELD_ANY			check for all fields (DEFAULT)

		or a bitwise combination of any of the above.
	*/
	logical HasField( const String& name, unsigned int fieldType = PLMXML_FIELD_ANY ) const; 

	//! Gets whether an attribute has a value and (if it does) whether its value is obtained by default.
	/*!
		@param	name	The name of the attribute.
		@param	explicitly	True if the value of the attribute has been set explicitly.
			False if the attribute acquires its value by virtue of it having a default.
			Undefined if the attribute does not have a value.
		@returns	True if the attribute has a value and false otherwise.
	*/
	logical HasAttributeValue( const String& name, logical& explicitly ) const;

	//! Resets the value of the attribute 'name' to its default value
	/*!
		If the attribute does not have a default value then it will be set to empty
	*/
	Result ResetAttributeValue( const String& name );

	//! Gets the values of all present attributes of the Object
	Result GetAttributeValues( Map<String,String>& values ) const;

	//@{ 
	//! Sets or gets an attribute of the object
	/*!
		@param	name	Name of the attribute field to set.
		@param	value	Value to set of the attribute field.

		If the attribute 'name' does not already exist on the object then it will first of all
		be created before it is set. 
		All values of all attributes can be obtained and set using the String version of 
		the functions. The specific overloaded versions of the functions will return an error 
		if the attribute cannot be represented as the specified type.

		Enumeration fields:

		An enumeration field can be set to a value not explictly allowed in a schema - in which case
		the SDK will return a warning message but allow the value to be set.
		NOTE: deliberately setting an enumeration field to a value not allowed by a schema will cause
		any document that is output to be invalid according to that schema.

        URI handling:

        URI strings can be accessed with Get/SetAttributeValue( name, String ) function.
        URI handles - with Get/SetAttributeValue( name, Reference ).

		For reference attributes (URI,IDREF) GetAttributeValue( name, Reference ) only returns
		the existing values of references - it does not resolve the references. To resolve the
		References call ResolveAttribuetValue.

	    If the string in Reference is left blank, SetAttribute( name, Reference ) 
        will not reset the string of the attribute.
	*/
	Result SetAttributeValue( const String& name, const String& value );
	Result GetAttributeValue( const String& name, String& value ) const;

	Result SetAttributeValue( const String& name, int value );
	Result GetAttributeValue( const String& name, int& value ) const;

	Result SetAttributeValue( const String& name, double value );
	Result GetAttributeValue( const String& name, double& value ) const;

	Result SetAttributeValue( const String& name, const Array<int>& value );
	Result GetAttributeValue( const String& name, Array<int>& value ) const;

	Result SetAttributeValue( const String& name, const Array<double>& value );
	Result GetAttributeValue( const String& name, Array<double>& value ) const;

	Result SetAttributeValue( const String& name, const Vector& value );
	Result GetAttributeValue( const String& name, Vector& value ) const;

	Result SetAttributeValue( const String& name, const Transf& value );
	Result GetAttributeValue( const String& name, Transf& value ) const;

    Result GetAttributeValue( const String& name, Reference& ref ) const;
    Result SetAttributeValue( const String& name, const Reference& ref );
	Result ResolveAttributeValue( const String& name, Reference& resolvedHandle, Configuration* resolveOptions = NULL );
    
	//! DEPRECATED: Use ResolveAttributeValue( String, Reference&, Configuration* )
	Result ResolveAttributeValue( const String& name, const Configuration& resolveOptions, Reference& resolvedHandle );
    
	/*!
	If the attribute is of type SingleReference or SingleURI, then the Array must be of
	length 0 or 1. If it is of length 0, the attribute will be Reset.
	*/
    Result SetAttributeValue( const String& name, const Array<Reference>& ref );
    
	Result GetAttributeValue( const String& name, Array<Reference>& ref ) const;
	Result ResolveAttributeValue( const String& name, Array<Reference>& resolvedHandles, Configuration* resolveOptions = NULL );
    
	//! DEPRECATED: Use ResolveAttributeValue( String, Array<Reference>&, Configuration* )	
	Result ResolveAttributeValue( const String& name, const Configuration& resolveOptions, Array<Reference>& resolvedHandles );
	//@}

    //! Appends a reference to an existing, multiple reference, attribute of the object
    /*!
        If the attribute 'name' does not already exist on the object then it will first of all
        be created as if the SetAttributeValue member function had been called.  If the
        attribute is already set, and is a single reference then the function will return an error.

        If the attribute 'name' exists then the Reference is appended to the existing attribute.  

        @param		name	The name of the attribute to modify.
        @param		ref		The reference to be appended.
        
		@returns	The result of the operation. 
    */
    Result AddAttributeValue( const String& name, const Reference& ref );

    //! Appends a reference to an existing, multiple reference, attribute of the object
    /*!
        If the attribute 'name' does not already exist on the object then it will first of all
        be created as if the SetAttributeValue member function had been called.  If the
        attribute is already set, and is a single reference then the function will return an error.

        If the attribute 'name' exists then the Reference is appended to the existing attribute.  
		
		The 'flags' argument controls the behaviour when an attribute already exists. 

        @param		name	The name of the attribute to modify.
        @param		ref		The reference to be appended.
		@param		flags	Options controlling the add reference operation. Can be one of the following 
							values:
								
								PLMXML_ADDREF_CHECK_EXISTING	
								
													Checks if the reference being added already exists. If it
													exists then an error is returned. If the reference doesn't already
													exist then it will be added as normal.
												
								PLMXML_ADDREF_NO_CHECK

													No attempt is made to check whether the attribute being added 
													already exists. Setting this option can improve the performance 
													of this functionality - but can lead to duplicate references.

								PLMXML_ADDREF_DEFAULT
								
													Provides the default AddReference behaviour. That is no checking
													of duplicate references will be performed.
        
		@returns	The result of the operation. 
		
						ErrorCodeAlreadyExists		If 'flags' is set to PLMXML_ADDREF_CHECK_EXISTING and an attribute 
													is being added that already exists.
    */
    Result AddAttributeValue( const String& name, const Reference& ref, unsigned int flags );

	//! Whether the object has any content
	logical HasContent( ) const;

	//! Resets any content of the object
	Result ResetContent( );

	//@{
	//! Sets or gets the content of the object
	/*!
		The contents of any child elements are not output. 
		
		All content of an element can be set/got using the String specific version of these functions. 
		The specific overloaded versions of these functions will return an error if the content
		cannot be represented as the specified type.
	*/
	Result GetContent( String& content ) const;
	Result SetContent( const String& content );
	
	Result GetContent( Transf& content ) const;
	Result SetContent( const Transf& content );

	Result GetContent( Vector& content ) const;
	Result SetContent( const Vector& content );

	Result GetContent( int& content ) const;
	Result SetContent( int content );

	Result GetContent( Array<int>& content ) const;
	Result SetContent( const Array<int>& content );

	Result GetContent( double& content ) const;
	Result SetContent( double content );

	Result GetContent( Array<double>& content ) const;
	Result SetContent( const Array<double>& content );
	//@}

	//! Returns all the child elements of the object
	Result GetElements( Array<Object*>& childElements ) const;

	//! Returns all the child elements of the object with the specified 'classType'
	/*
		'classType' can be qualified with a namespace in the form:

		\<namespace\>:\<classType\>		( http://www.plmxml.org/Schemas/PLMXMLSchema:Part )

		If no namespace is provided then the classType is assumed to be in the default
		PLM XML namespace.
	*/
	Result GetElementsByClass( const String& classType, Array<Object*>& childElements ) const;

	//! Returns all the child elements of the object with the specified 'fieldName'
	Result GetElementsByField( const String& fieldName, Array<Object*>& childElements ) const;


	//! Creates and adds a new child element
	/*! 
		'classType' specifies the class of the new element to add. It can either be qualified with 
		the namespace of the element in the form: \<namespace\>:\<class\> or unqualified. If the class type
		is unqualified it is assumed to be in the default PLM XML namespace.

		For child elements of a given class that could be added to more than one field then the 'fieldName'
		argument is used to specify which field to add an element to.
		
		If the child element type is plmxmlFieldSingleElement then any existing child element 
		of this name will be deleted and replaced. If the child element type is plmxmlFieldMultipleElement 
		then the child element is appended to the list of elements.
	*/
	Result AddElement( const String& classType, const String& fieldName, Object*& childElement );

	//! Creates and adds a new child element
	/*! 
		'classType' specifies the class of the new element to add.

		For child elements of a given class that could be added to more than one field then the 'fieldName'
		argument is used to specify which field to add an element to.
		
		If the child element type is plmxmlFieldSingleElement then any existing child element 
		of this name will be deleted and replaced. If the child element type is plmxmlFieldMultipleElement 
		then the child element is appended to the list of elements.
	*/
	Result AddElement( plmxmlClass classType, const String& fieldName, Object*& childElement );

	//! Adds an existing element as a child element of this object.
	/*!
		If 'pObject' has a Null id, it will be allocated one of the form id<integer>.

		If there are objects in the trees with the same id, the function will fail, unless
		the ids were allocated by the SDK; in which case the id in the child tree will
		be replaced by a new one, and all references to it from within the child tree will
		be updated, whether IDREF or URI (i.e. of the form "#id123").

		The child object will be added to the first suitable field of the parent. Suitable 
		means that the class of the field is a base class of the class of the child, and 
		that the field is not an already-occupied single element field.
	*/
	Result AddElement( Object* pObject );

	//! Adds an existing element as a child element of this object.
	/*!
		@param	pObject		The Object to add as a child Object of this Object.
		@param	field		The name of the 'field' of the Object to add the child Object.
								The field must be an element based field whose class is a base 
								class of the child Object to add. The field must also not be an 
								already-occupied single element field.
		@returns				The Result of the operation.

	If 'pObject' has a Null id, it will be allocated one of the form id<integer>.

	If there are objects in the trees with the same id, the function will fail, unless
	the ids were allocated by the SDK; in which case the id in the child tree will
	be replaced by a new one, and all references to it from within the child tree will
	be updated, whether IDREF or URI (i.e. of the form "#id123").
	*/
	Result AddElement( Object* pObject, const String& field );

	//! Deletes all the child elements of this object
	Result DeleteElements( );

	//! Delete the supplied child element of this object
	Result DeleteElement( Object* pObject );

	//! Deletes all child elements of this object with the specified 'classType'
	/*!
		'classType' can either be qualified with the namespace of the classType in the form: 

			\<namespace\>:\<class\> 
		
		or unqualified. If the class type is unqualified then it is assumed to be in the 
		default PLM XML namespace.
	*/
	Result DeleteElementsByClass( const String& classType );

	//! Deletes all child elements in the specified field
	Result DeleteElementsByField( const String& fieldName );

	//! Select elements of sub-tree according to XPath 'xpath' selection string.
    Result SelectElements( const String& xpath, Array<Object*>& selectedObjects );

	//! Selects items according to an XPATH expression.
	/*!
		@param	xpath			A String representing a valid XPATH expression.
		@param	selection		A Selection object containing the results of the XPATH selection. 
									This may be an empty Object is nothing has been selected.
		@returns					The result of the XPATH selection. Will be an error if the XPATH
									selection string is invalid or the XPATH selection could not be 
									carried out.
	*/
    Result Select( const String& xpath, Selection& selection );

	//! Returns the name of this element
	/*!
		For example if this is a RefPoint object whose parent is a Line object, and which is the
		sub-element corresponding to the StartPoint field then this will return "StartPoint"
	*/
	String GetElementName( ) const;

	//! Lookup an object by its Id
	/*
	This will return the object with the given Id, in the same tree as this one.
	*/
    Object *ResolveId( const String& id ) const;

	//! Save the Object and its tree of sub-elements.
	/*!
		@param	uri			The URI to save the Object to. The function will attempt to open the given URI 
							using URI Resolver and write to that. Pre-existing streams can be used by implementing 
							custom URI Resolvers.
		@param	saveOptions	Specifies any options to use for the save operation.
		@returns			Result of the save operation.

		@deprecated	Use plmxml_api::Object::Save( const String& uri, Configuration* saveOptions ) instead.
	*/
	Result Save( const String& uri, const Configuration& saveOptions );

	//! Save the Object and its tree of sub-elements.
	/*!
	    @param	uri				The URI to save the Object to. The function will attempt to open the given URI 
								using URI Resolver and write to that. Pre-existing streams can be used by 
								implementing custom URI Resolvers.
		@param	saveOptions		Specifies the options to use when saving the Object. If no options are specified 
								then any global options (as specified by ConfigurationRef) will be used. If no
								global options are specified then the default (empty) options will be used. 
								Options specified locally to this function will be used in preference to any 
								global options.

		\note
		The document will be saved out encoded into UTF-8
	*/
	Result Save( const String& uri, Configuration* saveOptions = NULL );

	//! Get the Object and its tree of sub-elements as an XML String.
	/*!
		@param	xml			The returned XML representation of the Object and its content. 
		@param	options		Optional options for the operation. Any options valid for a Save operation will be valid for this operation. Although it should be noted that those options related to saving out referenced documents and files will be ignored.
		@returns				The result of the operation.

		The XML representation of the Object and its sub-elements is the same as that
		produced if the Object were saved - with the exception that XML is not generated for
		externally referenced data.
	*/
	Result GetXML( String& xml, Configuration* options = NULL ) const;

	//! Resolve id conflict between this object tree and a given tree.
	Result ResolveIdConflict( Object *parent, logical allIds );

	//@{
	//! Deprecated functionality
	Result	GetAttributeTypes( Map<String,plmxmlFieldType>& mAttribTypes ) const;
	logical HasAttribute( const String& attribName, logical& isPresent ) const;
	Result	ResolveAttribute( const String& name, Array<Handle>& resolvedHandles );
	Result	GetChildElementTypes( Array<FieldType>& aFieldTypes ) const;
	Object*	AddChildElement( const String& fieldName, Result& res );
	Result	DeleteAttribute( const String& name );
	Result	GetChildElements( Array<Object*>& childElements ) const;
	Result	GetChildElements( const String& name, Array<Object*>& childElements ) const;
	Result	DeleteChildElement( Object* pObject );
	String	GetChildElementName( const Object* childElement ) const;
	//@}

	//! Internal function
	virtual ClassData*	GetImplementation( ) const;

	//! Creates a copy of the Object.
    /*
		@param	copy		The returned copy of the Object. In the case of a failure this will be 
							a NULL pointer.

		@param	flags		Options controlling the copy operation. Can be a bitwise combination of:
								
								PLMXML_COPY_OBJECT	Performs a shallow copy of the Object. Only the 
													attributes and content of the Object are copied.
													Any child elements of the Object will not be copied.

								PLMXML_COPY_DEEP	Performs a deep copy of the Object. The attributes 
													and content of the Object are copied. Any child 
													elements of the Object are copied recursively.
												
								PLMXML_COPY_DEFAULT	Default copy options. Currently performs a deep copy
													of the Object
													
								PLMXML_COPY_GENERIC	Internal
		
		@returns			The result of the operation.
	*/
	Result Copy( Object*& copy, unsigned int flags=PLMXML_COPY_DEFAULT ) const;

protected:

	//! Internal functionality
	logical InitData( plmxmlClass classType );

private:

	//! Internal Field
	ClassData*   m_pImpl;
};

//////////////////////////////////////////////////////////////////////////////////////

/*! \defgroup PluginConfig Configuration settings
	see plmxml_api::Configuration class for details how to apply these options.
*/
/*! \addtogroup PluginConfig
	<b>Options for the built-in PLMXML adapter</b>

	The following options can be used during plmxml_api::Load operation.

    \verbatim
    format       - specifies the format of the source if ambiguous.
                    "PLMXML", "XT", "JT" etc.

    adapters
        PLMXML
            namespaces
                HD  http://www.jumpstart.plmxml.org/Schemas/HeaderAttribute
                HD2 http://www.newhd.org/Schemas/HeaderAttribute

	adapters
		PLMXML
			ignore_unknown_elements	- Option to specify the behaviour when loading XML files 
									and encountering unknown element types. 
									If this is set to "true" the unknown elements are ignored 
									and an error is raised (Default).
									If set to "false" then unknown elements are constructed as
									generic objects that can be accessed through the base Object 
									API.

			validation				
				load_save			- Controls the level of validation of PLM XML data that the 
									SDK performs during load and save operations. 
									
									Allowed values:
										
										"standard"	- Perform the standard level of validation 
													(Default)

										"minimal"	- Perform a reduced level of validation.
													
													This option can be used to improve the performance
													of loading and saving of PLM XML data in the SDK. 
													However, it should only be used when it is known
													that the data is already valid. Failure to
													do so could lead to either unpredictable behaviour 
													or the generation of invalid PLM XML.

	\endverbatim

	The following options can be used during plmxml_api::Object::Save operation.
        
    \verbatim
    format       - specifies the format of the target if ambiguous.

    adapters

        PLMXML

            export

                prolog          - the option to save the prolog (<?xml ... >). Defaults to TRUE.
                                    "true", "false"

                namespace_list  - option to save the namespaces (xmlns="..."). Defaults to TRUE.
                                    "true", "false"

				stylesheet		- Outputs a stylesheet directive as part of the prolog of the XML in 
								the form:

									<?xml:stylesheet type="text/xsl" href="<stylesheet value>"?>. 
								
								This option requires that the 'prolog' option is switched on. 
								Defaults to no stylesheet information output.

				escape			- Provides control over which characters are escaped in the generated
								PLM XML.

									"default"		- The following characters will be escaped:

														'<'		as '&lt;'
														'&'		as '&amp;'
														'"'"	as '&quot;'

													This is the default.

									"escape_gt"		- Escapes characters as for the "default" value but
													in addition escapes the '>' character as '&gt;'

				line_break		- Provides control over line breaks in multiple reference attributes only,
								if unset (Default) there is no line breaking.  There is also no line
								breaking if line_break is set to 0.

								If set to a value greater than 0 then the line is broken at a white 
								space at or before the line length specified, this is only applicable
								for lines whose lengths exceed the line break value. 

								The line will be broken at the first whitespace before the line_break 
								limit.  If the limit is less than the length of the first reference on 
								a line then the line will be broken immediately after that reference.

	\endverbatim

	Treatment of reference (URI) attributes can be controlled for Load and Save using the 
	following options:

    \verbatim
    adapters
        PLMXML
			references			- the option controlling how SDK deals with references when
								  loading or saving PLMXML. Allowed values:
									"resolve"	- SDK will attempt to resolve every reference when loading
												  or saving a document. This is the default.

									"translate" - URI attributes will be translated into a form which
												  would allow them to be used/resolved later. See 
												  comment below.

									"off"		- no resolving or translation.

	"translate" option is particularly important for filetypes that contain 'local' references, i.e. 
	the references do not have a path - <Representation location="#PLMXML(ABC-doc/....)">. SDK is able to 
	resolve such references only during the file loading. If these references are to be resolved later, 
	they need to be translated into a full URI - <Representation location="c:\dir\file.abc#PLMXML(ABC-doc/....)">

    \endverbatim

	The following options can be used for Load and Save operations as well as SetAttributeValue operations:

	\verbatim

	adapters
		PLMXML
			empty_attributes		- Option to specify the behaviour for handling empty ("") 
									attributes of type: plmxmlFieldString, plmxmlFieldSingleReference,
									plmxmlFieldMultipleReference, plmxmlFieldSingleURI and plmxmlFieldMultipleURI

									"default"		- Attributes of the specified types set to "" are considered
													to be absent. (Default)
									"treat_as_set"	- Attributes of the specified types set to "" are considered 
													to be present and to have the value of ""

	\endverbatim

	<b>Scalability options</b>

	The memory usage behaviour of the SDK when loading and constructing large document models can be controlled.
	An option can be used to 'serialise' data out of memory to an alternate location when it it not being 
	used (and to subsequently load in the data when it is required). This can be used to reduce the amount 
	of memory used by the SDK.

	\verbatim

	serialise					- Whether serialisation of data should occur
										"true"	- Serialisation of data will occur
										"false"	- No serialisation of data will occur (default).
		
		cache_location				- The location at which any cache file will be created. By default a cache file
									will be created in the temporary directory as defined by any environment variables.
									Failing this it will be created in the current directory.
		
		threshold					- The absolute number of live Objects that can exist at one time before
									serialisation will occur. (1000000)

		cache_pool_size				- The size of a pool containing recently accessed Objects. Any Objects will not be
									serialised whilst they remain in the pool. (100)

		callbacks					- The data associated with this option must be an instance of the SerialisationCallback
									interface which will be used during serialisation. (NULL)
									Note: A given callback interface must remain valid for the lifetime of all Objects created
									during the scope of the callback interface.

	\endverbatim

	<b>Adapter and Resolver instance options</b>

	Control over which adapters to use for the scope of the Configuration is provided by the following options:

	\verbatim

	adapters
		XT, JT, ...
			instance				- The address of an instance of an Adapter of the specified 
									format. This single instance of the adapter will be used 
									in the SDK as long as the Configuration object remains in 
									scope. Note: it is the applications responsibility to 
								    delete the instance.

	\endverbatim

	Provides control over which URI Resolver to use for the scope of the Configuration. Any active URI Resolver
	specified by an instance of the URIResolverRef class will take precedence over this option.

	\verbatim

	uri_resolver
			instance			- The address of an instance of a URIResolver. This single instance
								  of a URI Resolver will be used by the SDK for as long as the Configuration
								  object remains in scope. Note: it is the applications responsibility to 
								  delete the instance.

    \endverbatim

	<b>Adapter substitution option</b>

	Allows substitution of adapters while resolving references.

	\verbatim

	adapters
		substitute
								- Comma separated list of adapter name pairs 
								  e.g. "JT/NXTag,XT/MyXT,JT/MyJTAdapter".
								  When resolving references the SDK will replace
								  all instances of the first adapter with the second.
	\endverbatim
*/

/*! \class Configuration
    \brief Configuration class

    This class represents the \<Configuration\> element, which is used to define 
    control parameters for PLM XML SDK plugins (adapters).
*/
class PLMXML_API Configuration : public Object 
{
public:

	//! Default constructor
	Configuration(); 
	
	//! Constructs a Configuration with the specified parent.
	/*!
		If the parent of this object cannot be set a Exception
		is thrown.
    */
	Configuration( Object* parent ); 
	
	// Destructor
	virtual ~Configuration(); 

    //@{
	//! Set a Configuration property value using / separated path, return pointer to it.
    /*!
        For example:
        Configuration* ptr = config->Set( "adapters/PLMXML/prolog", "true" );
        would create:

        \verbatim
        config -> <Configuration ...>
                    <Configuration name="adapters">
                      <Configuration name="PLMXML">
        ptr ->          <Configuration name="prolog" value="true">
        \endverbatim

        if any of the elements in the hierarchy do not exist.

        In a similar way:
        Configuration* ptr = config->Set( "format", "PLMXML" );

        \verbatim
        config -> <Configuration ...>
        ptr ->      <Configuration name="format" value="PLMXML">
        \endverbatim
    */
    Configuration* Set( const String& path, const String& value );
	Configuration* Set( const String& path, const String& value, const PLMXML_MODELLER_HANDLE ptr );
	//@}

    //@{
	//! Finds first entry in the hierarchy satisfying the 'path' specification.
    /*!
        For example:
        \verbatim
        config -> <Configuration ...>
                    <Configuration name="adapters">
                      <Configuration name="PLMXML">
        ptr ->         <Configuration name="prolog" value="true">
        \endverbatim

        String value;
        Configuration* ptr = config->Get( "adapters/PLMXML/prolog", value );
    */
    Configuration* Get( const String& path, String& value ) const;
    Configuration* Get( const String& path, String& value, PLMXML_MODELLER_HANDLE& ptr ) const;
	//@}
	
private: 
	
	//! Assignment operator
	Configuration& operator=(const Configuration& iSrc ); 
	
public: 
	//! Copy constructor
	Configuration( const Configuration& original ); 



	//! Get the Name of this Configuration
	String GetName() const; 

	//! Set the Name of this Configuration
	Result SetName( const String &s );

	//! Check if Name has been set
	logical HasName( ) const; 
	
	//! Unset Name
	Result UnsetName( );

	//! Get Value of this Configuration
	String GetValue() const; 

	//! Set Value of this Configuration
	Result SetValue( const String &s );

	//! Check if Value has been set
	logical HasValue( ) const;

	//! Unset value
	Result UnsetValue( ); 
	
	//! Add Configuration child element to this Configuration. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Configuration *AddConfiguration();

	//! Add 'arg' as Configuration child element to this Configuration.
	Result AddConfiguration( Configuration *arg );

	//! Detach and delete all Configuration child elements.
	void DeleteConfigurations(); 

	//! Get number of Configuration child elements.
	int NumberOfConfigurations() const; 

	//! Get i'th Configuration child element.
	Configuration *GetConfiguration( int i ) const;

	//! Get all Configuration child elements as an array.
	void GetConfigurations( Array<Configuration*> &array ) const; 

	//! Detach and delete i'th Configuration child element.
	void DeleteConfiguration( int i );

	//! Detach and delete 'arg' if it's one of the Configuration child elements.
	void DeleteConfiguration( Configuration *arg ); 

}; extern PLMXML_API plmxmlClass plmxmlClassConfiguration;

//////////////////////////////////////////////////////////////////////

class ConfigurationRefImpl;

//! ConfigurationRef class.
/*!
	Helper class that is used to set an instance of a Configuration to be 
	active within the scope of the ConfigurationRef.

	The options specified in the the Configuration of the ConfigurationRef 
	class will be used by functions called within the scope of the 
	ConfigurationRef instance. Options specified locally to these functions
	will take precedence over any active ConfigurationRef options.
*/
class PLMXML_API ConfigurationRef : public Allocator
{
	//! Internal Data.
	ConfigurationRefImpl*	m_pImpl;

public:

	//! Constructs a new instance of a ConfigurationRef.
	/*!
		@param		configuration	An instance of an existing Configuration object whose options will be set
									to be active for the scope of this ConfigurationRef.
	*/
	ConfigurationRef( Configuration* configuration );

	//! Destructor.
	~ConfigurationRef( );

	//! Provides access to contained Configuration.
	/*!
		@returns	The underlying Configuration object.
	*/
	Configuration* operator->( ) const;

	//! Returns the currently active Configuration.
	/*!
		@returns     The active Configuration - or NULL if no Configuration is currently active.
	*/
	static Configuration* GetActiveConfiguration( );

	//! Internal function
	ConfigurationRefImpl* GetImplementation( ) const;
};

//////////////////////////////////////////////////////////////////////
//! Class SerialisationCallback
/*!
	Base class that defines a callback function that is used to provide 
	control over serialisation and deserialise of data for the SDK at runtime. 
*/
class PLMXML_API SerialisationCallback
{
public:
	// !Constructor
    SerialisationCallback();
    
	// !Destructor
	virtual ~SerialisationCallback();

	// Callback made by the SDK to begin serialisation of an item of data.
	/*!
		The implementation of this function must return a valid Stream associated
		with the supplied 'id'. 
		
		@param		id			Unique identifier to be associated with the data to be serialised.
		@param		pStream		Returned Stream that the serialised data will be written to.
		@returns				Result of the operation
	*/
	virtual Result BeginSerialise( const String& id, Stream*& pStream ) = 0;
	
	// Callback made by the SDK to end serialisation of an item of data.
	/*!
		@param		id			Unique identifier for the data. This identifier will be the same as that
								passed into the matching BeginSerialise callback.
		@param		pStream		The Stream object that was originally returned by the matching 
								BeginSerialise callback.
		@param		result		The result of the serialisation.
		@returns				Result of the operation.
	*/
	virtual Result EndSerialise( const String& id, Stream* pStream, const Result& result ) = 0;

	// Callback made by the SDK to begin de-serialisation of an item of data.
	/*!
		The implementation of this function must return a valid Stream associated
		with the supplied 'id'. 
		
		@param		id			Unique identifier to be associated with the data to be serialised.
		@param		pStream		Returned Stream that the data will be de-serialised (read) from.
								The stream returned must be the same stream as that originally supplied
								from a BeginSerialise callback with the given id.
		@returns				Result of the operation
	*/
	virtual Result BeginDeSerialise( const String& id, Stream*& pStream ) = 0;

	// Callback made by the SDK to end de-serialisation of an item of data.
	/*!
		@param		id			Unique identifier for the data. This identifier will be the same as that
								passed into the matching BeginDeSerialise callback.
		@param		pStream		The Stream object that was originally returned by the matching 
								BeginDeSerialise callback.
		@param		result		The result of the de-serialisation.
		@returns				Result of the operation.
	*/
	virtual Result EndDeSerialise( const String& id, Stream* pStream, const Result& result ) = 0;
};

//////////////////////////////////////////////////////////////////////

#define plmxmlLinkType			int
#define plmxmlLinkTypeClass		0
#define plmxmlLinkTypePlugin	1

// Forward declaration
class ClassDescriptor;

/////////////////////////////////////////////////////////////////////
// For internal use by the plmxml toolkit and initialisation macros
//////////////////////////////////////////////////////////////////////

//! Internal
typedef Object* (*PLMXML_FN_GET_INSTANCE)( );

//! Internal
typedef logical (*PLMXML_FN_REGISTER)( void* );

// Forward declaration
class LinkNodeImpl;

// LinkNode class
/*
	Maintains a list of functions that need to be called to 
	register an Object.
*/
class PLMXML_API LinkNode
{
	friend class LinkNodeImpl;

	// Head node of the list
	static LinkNode*		m_pHeadNode;	

	// Tail node of the list
	static LinkNode*		m_pTailNode;

	// Previous node in list
	LinkNode*				m_pPreviousNode;

	// Next node in list
	LinkNode*				m_pNextNode;

	// Function to call to register Object
	PLMXML_FN_REGISTER		m_pRegisterFn;

	// The type of the link object
	const plmxmlLinkType	m_Type;

	// Internal field
	void*					m_pObject;

	// Whether this LinkNode has been registered yet
	logical					m_isRegistered;

	// Node at which we need to start registering other nodes
	/*
		Used when loading extension code after ClassDescriptors have already
		been registered.
	*/
	static LinkNode*		m_pRegisterNode;

public:

	// Constructor
	LinkNode( PLMXML_FN_REGISTER registerFn, plmxmlLinkType type );

	// Destructor
	virtual ~LinkNode( );

	// overloaded assignment operator
	void operator=(const LinkNode&);
};

//////////////////////////////////////////////////////////////////////
class ClassDescriptorImpl;

//! ClassDescriptor class.
/*!
	The ClassDescriptor class represents an <xsd:complexType> in a schema file. It provides the support in the SDK
	for a given PLM XML schema. ClassDescriptors can either be created indirectly by linking in code that supports
	a given schema or alternatively by directly loading a PLM XML schema into the SDK.
*/
class PLMXML_API ClassDescriptor
{	
public:

	//! Returns the plmxmlClass associated with this ClassDescriptor.
	/*!
		@returns	The plmxmlClass of this ClassDescriptor.
	*/
	const plmxmlClass& GetClass( ) const;

	//! Sets the class name of this type.
	/*!
		@param	name	The name of the ClassDescriptor. This should be in an unqualified form.
	*/
	void SetName( const String& name );

	//! Gets the name of this type.
	/*!
		@returns	The name of the ClassDescriptor.
	*/
	const String& GetName( ) const;

	//! Sets the version of the schema.
	/*!
		@param	version		The version of the PLM XML schema that the ClassDescriptor represents a type in ("6.0","5.1").
	*/
	void SetVersion( const String& version );

	//! Gets the version of the schema.
	/*!
		@returns	The version of the PLM XML schema that this ClassDescriptor represents.
	*/
	const String& GetVersion( ) const;

	//! Sets whether this ClassDescriptor is deprecated.
	/*!
		@param	deprecated		<Code>TRUE</Code> if this ClassDescriptor is to be deprecated - <Code>FALSE</Code> otherwise.
									By default a ClassDescriptor is assumed to not be deprecated.
	*/
	void SetDeprecated( logical deprecated );

	//! Gets whether this ClassDescriptor is deprecated.
	/*!
		@returns	<Code>TRUE</Code> if this ClassDescriptor is deprecated - <Code>FALSE</Code> otherwise.
	*/
	logical GetDeprecated( void ) const;

	//! Sets the output name of this type.
	/*!
		@param	name	The name of the corresponding type in the schema.
	*/
	void SetOutputName( const String& name );

	//! Returns the output name for this type.
	const String& GetOutputName( ) const;

	//! Gets the qualified name of this type.
	/*!
		@returns	The qualified name of the type. The name will be qualified in the following form:

					\<namespace\>:\<name\>

					For example:

					"http://www.plmxml.org/Schemas/PLMXMLSchema:ProductRevisionView"
	*/
	const String& GetQualifiedName( ) const;

	//! Returns the namespace associated with this ClassDescriptor.
	/*!
		@returns	The XML namespace of the type that this ClassDescriptor represents.
	*/
	const String& GetNamespace( ) const;

	//! Returns the namespace prefix associated with this ClassDescriptor.
	/*!
		@returns	The namespaces prefix ( "plm", "bus", ... ).
	*/
	const String& GetNamespacePrefix( ) const;

	//! Sets the namespace of the type represented by this ClassDescriptor.
	/*!
		@param	nspace			The XML namespace of the type.
		@param	nspacePrefix	The namespace prefix to use as shorthand for the XML namespace.
		@returns					<code>TRUE</code>If the namespace is set correctly - <code>FALSE</code> otherwise.
	*/
	logical SetNamespace( const String& nspace, const String& nspacePrefix );

	//! Set the function used to make a new instance.
	/*!
		@param	makeFunction	The function to call to create a new instance of the Object that this ClassDescriptor represents.
	*/
	void SetMakeFunction( PLMXML_FN_GET_INSTANCE makeFunction );

	//! Sets the base class of the type represented by this ClassDescriptor.
	/*!
		@param	baseClass	The base class of the ClassDescriptor. This can be qualified by the namespace 
								in the form:

									\<namespace\>:\<base_class_name\>.

								If no namespace is specified then it is assumed that the base class is 
								in the default PLM XML namespace.
		@returns	<code>TRUE</code>If the base class has been successfully set - <code>FALSE</code> otherwise.
	*/
	logical SetBaseClass( const String& baseClass );

	//! Returns the base class of the schema type represented by this ClassDescriptor.
	/*!
		@returns	The base class returned can be qualified by the namespace in the form:
					
						\<namespace\>:\<base_class_name\>.
		
					If no namespace is specified then the default PLM XML is assumed.
	*/
	const String& GetBaseClass( ) const;

	//! Returns the resolved base class.
	/*!
		@returns	The resolved base class. If the ClassDescriptor does not have a base class specified 
					then the plmxml_api::Object ClassDescriptor is returned. If the ClassDescriptor cannot
					be resolved then a NULL reference is returned.
	*/
	const ClassDescriptor *GetBaseClass( );

	//! Sets the equivalence class of the type represented by this ClassDescriptor.
	/*!
		@param	equivalenceClass	The equivalence class / substitutionGroup for the ClassDescriptor.
										The equivalence class specified can be qualified by the namespace 
										in the form:
								
											&lt;namespace&gt;:&lt;equivalence_class_name&gt;. 
		
										If the equivalence class is not qualified then it is assumed to be
										in the default PLM XML namespace.
		@returns	<code>TRUE</code>If the equivalence class has been successfully set - <code>FALSE</code> 
					otherwise.
	*/
	logical SetEquivalenceClass( const String& equivalenceClass );

	//! Returns the equivalence class.
	/*!
		@returns	The equivalence class of the ClassDescriptor. If no equivalence class has been specified
					an empty string will be returned.
	*/
	const String& GetEquivalenceClass( ) const;

	//! Returns the resolved equivalence class.
	/*!
		@returns	The resolved equivalence class. If no equivalence class has been previously specified then
					a NULL reference will be returned.
	*/
	const ClassDescriptor *GetEquivalenceClass( );

	//! Sets whether the class is abstract.
	/*!
		@param	<code>TRUE</code> if the class is abstract. <code>FALSE</code> otherwise.
		@returns	<code>TRUE</code> if successful. <code>FALSE</code> otherwise.
	*/
	logical SetIsAbstract( logical isAbstract );

	//! Returns whether the class is abstract.
	/*!
		@returns	<code>TRUE</code> if the class is abstract. <code>FALSE</code> otherwise.
	*/
	logical GetIsAbstract( ) const;

	//! Adds a new field to this ClassDescriptor.
	/*!
		@param	name	Name of the field to register.
		@param	type	Type of the field to register.
		@returns	<code>TRUE</code> If the field could be registered. <code>FALSE</code> if the field could
					not be registered or a field of the same name already exists.
	*/
	logical RegisterField( const String& name, plmxmlFieldType type );

	//! Sets the class type of an existing field.
	/*!
		@param	name		Name of the field to set.
		@param	classType	Class of the field to set. The class specified can be qualified by the 
								namespace in the form:
								
									\<namespace\>:\<class\>. 
		
								If classType is not qualified then it is assumed to be in the default PLM XML 
								namespace.
		@param	resolveNamespace	Whether to try and resolve the 'classType' of the field in namespaces
										other than that of the owning ClassDescriptor. (FALSE)
		@returns	<code>TRUE</code> if the field class could be set. <code>FALSE</code> if the field class 
					could not be set or the field could not be found.
	*/
	logical SetFieldClass( const String& name, const String& classType, logical resolveNamespace = FALSE );

	//! Sets the length of a field.
	/*!
		A length can only be associated with attributes and content fields based on one of the following types:

				plmxmlFieldInt
				plmxmlFieldDouble
				plmxmlFieldLogical
				plmxmlFieldVector
				plmxmlFieldMatrix

		@param	name	Name of the field to set.
		@param	length	Length of the field (1)
								0		Variable length array
								1		Fixed length single field
								> 1		Fixed length multiple field.
		@returns	<code>TRUE</code> if the length of the field could be set. <code>FALSE</code> if the length
					could not be set or the field could not be found.
	*/
	logical SetFieldLength( const String& name, int length );

	//! Sets whether the existing field is required.
	/*!
		@param	name		Name of the field to set.
		@param	required	Whether this field is required (FALSE).
		@returns	<code>TRUE</code> if the field could be set. <code>FALSE</code> otherwise.
	*/
	logical SetFieldRequired( const String& name, logical required );

	//! Sets the default value of an existing field.
	/*!
		@param	name		Name of the field to set.
		@param	required	The default value of this field ("").
		@returns			<code>TRUE</code> if the default value of the field could be set. <code>FALSE</code> 
							otherwise.
	*/
	logical SetFieldDefault( const String& name, const String& required );

	//! Sets whether the existing field is deprecated.
	/*!
		@param	name			Name of an existing field.
		@param	deprecated		<Code>TRUE</Code> if this field is to be set as deprecated - <Code>FALSE</Code> otherwise.
		@returns				<code>TRUE</code> if the the field could be set. <code>FALSE</code> otherwise.
	*/
	logical SetFieldDeprecated( const String& name, logical deprecated );

	//! Sets the possible values that this field is allowed.
	/*!
		Currently it is only valid to set the allowed values for enumeration based fields.

		@param	name		Name of an existing field.
		@param	values		An array of the allowed enumeration values. The last entry in the array must be 
								NULL.
		@returns	<code>TRUE</code> if the default values for the field could be set. <code>FALSE</code> 
					otherwise.
	*/
	logical SetFieldAllowedValues( const String& name, const char* values [] );

	//! Get the field types for the object.
	/*!
		@param	types		Array of allowed fields of the ClassDescriptor. If no fields are allowed for the
								ClassDescriptor then the array will be empty.
		@param	fieldTypes	Provides control over which types of fields to return. May be one of the 
								following:

									\verbatim
									PLMXML_FIELD_ATTRIBUTE		return all attribute fields
									PLMXML_FIELD_ELEMENT		return all element fields
									PLMXML_FIELD_CONTENT		return all content fields
									PLMXML_FIELD_ANY			return all fields of the object
									\endverbatim

								or a bitwise combination of any of the above.	(PLMXML_FIELD_ANY)
		@param	includeBaseClasses	<code>TRUE</code> if field should be returned from base classes as well 
										as the current class or <code>FALSE</code> otherwise. (TRUE).
		@returns	The result of the operation.
	*/
	Result GetFields( Array<FieldInfo>& types, unsigned int fieldTypes = PLMXML_FIELD_ANY, logical includeBaseClasses = TRUE ) const;

	//! Get the type of the field with a specified name.
	/*!
		@param	name	Name of the field to return.
		@param	type	Returned information for the field. If the specified field cannot be found then this
							will be unset.
		@param	fieldType	Provides control over which types of fields to return. May be one of the following:

									\verbatim
									PLMXML_FIELD_ATTRIBUTE		return all attribute fields
									PLMXML_FIELD_ELEMENT		return all element fields
									PLMXML_FIELD_CONTENT		return all content fields
									PLMXML_FIELD_ANY			return all fields of the object
									\endverbatim

								or a bitwise combination of any of the above.	(PLMXML_FIELD_ANY)
		@returns	The result of the operation.
	*/
	Result GetField( const String& name, FieldInfo& type, unsigned int fieldType = PLMXML_FIELD_ANY ) const;

	//! Whether the specified field is an allowed field.
	/*!
		@param	name		Name of the field to return.
		@param	fieldType	Provides control over which types of fields to check for. May be one of the 
								following:

									\verbatim
									PLMXML_FIELD_ATTRIBUTE		return all attribute fields
									PLMXML_FIELD_ELEMENT		return all element fields
									PLMXML_FIELD_CONTENT		return all content fields
									PLMXML_FIELD_ANY			return all fields of the object
									\endverbatim

								or a bitwise combination of any of the above.	(PLMXML_FIELD_ANY)
		@returns	<code>TRUE</code> if 'name' is an allowed field - <code>FALSE</code> otherwise.
	*/
	logical IsField( const String& name, unsigned int fieldType = PLMXML_FIELD_ANY ) const;

	//! Whether the ClassDescriptor is allowed content.
	/*!
		@returns	<code>TRUE</code> if this is allowed content - <code>FALSE</code> otherwise.
	*/
	logical HasContent( ) const;

	//! Makes a new instance of an object based on this ClassDescriptor.
	/*!
		@returns	A new instance of Object that the ClassDescriptor represents. If the Object could
					not be generated a NULL reference will be returned.
	*/
	Object *MakeObject( ) const;

	//! Gets the concrete classes derived from the abstract class.
	/*!
		@param	concreteClasses	An array of concrete classes derived from this abstract class.
		@returns	<code>TRUE</code> if successful. <code>FALSE</code> otherwise.
	*/
	logical GetConcreteClasses( Array<ClassDescriptor*>& concreteClasses ) const;

	//! Internal Function.
	ClassDescriptorImpl*	GetImplementation( ) const;

	//! The number of ClassDescriptors registered.
	/*!
		@returns	The number of different ClassDescriptors registered.
	*/
	static int NumberOfClassDescriptors( );

	//! Returns a specific ClassDescriptor.
	/*
		@param	i	Index of the ClassDescriptor to return.
		@returns		The ClassDescriptor at the specified index or NULL if the index is out of range.
	*/
	static ClassDescriptor* GetClassDescriptor( int i );

	//! Lookup an existing ClassDescriptor based on a name.
	/*!
		@param	name	Name of the ClassDescriptor to find. The name of the ClassDescriptor can either
							be qualified with the XML namespace or the namespace prefix:

								\<namespace/namespace prefix\>:\<name\> 
		
							If no qualification exists then the ClassDescriptor is assumed to be in the  default 
							PLM XML namespace.
		@returns	The found ClassDescriptor or NULL if no ClassDescriptor has been found that matches the 
					supplied 'name'.
	*/
	static ClassDescriptor* FindByName( const String& name );

	//! Find a ClassDescriptor based on a plmxmlClass.
	/*!
		@param	classType	The class of the ClassDescriptor to find.
		@returns	The found ClassDescriptor or NULL if no ClassDescriptor is found that matches the supplied
					'classType'.
	*/
	static ClassDescriptor* FindByClass( plmxmlClass classType );

private:

	friend class ClassDescriptorImpl;

	// !Default Constructor
	ClassDescriptor( );

	// !Destructor
	virtual ~ClassDescriptor();

	// !Internal Data
	ClassDescriptorImpl*			m_pImpl;

public:

	//! Resets ClassDescriptor support to initial value.
	/*
		Any ClassDescriptors that provide support for the main PLM XML schema or those ClassDescriptors
		which are created as the result of loading extension code will be reset to their original values.
		ClassDescriptors created as a result of loading a schema file (either directly or indirectly) 
		will be deleted.
		
		@returns	The result of the operation.
	*/
	static Result Reset( );

	//! Resets any ClassDescriptors that exist in the specific XML namespace.
	/*!
		@param		nspace	The XML namespace for which to reset the ClassDescriptors.
		@returns			The result of the operation.
	*/
	static Result Reset( const String& nspace );

	//! Sets the schema name for the ClassDescriptor.
	/*
		@param	name	The name of the corresponding type exactly as it appears in the schema.
	*/
	void SetSchemaName( const String& name );

	//! Sets a property of the ClassDescriptor.
	/*!
		@param	name	Name of the property to set. This must be an existing (known) property of the ClassDescriptor.
		@param	value	Value of the property to set.
		@returns		The result of the operation. 
	*/
	Result SetProperty( const String& name, const String& value );

	//! Sets a property of the ClassDescriptor.
	/*!
		@param	name	Name of the property to set. This must be an existing (known) property of the ClassDescriptor.
		@param	value	Value of the property to set.
		@param	data	Any additional data associated with the property.
		@returns		The result of the operation. 
	*/
	Result SetProperty( const String& name, const String& value, PLMXML_MODELLER_HANDLE data );

	//! Gets a property of the ClassDescriptor.
	/*!
		@param	name	Name of the property to get the value of. This must be an existing (known) property
						of the ClassDescriptor.
		@param	value	Value of the requested property.
		@returns		The result of the operation.
	*/
	Result GetProperty( const String& name, String& value ) const;

	//! Gets a property of the ClassDescriptor.
	/*!
		@param	name	Name of the property to get the value of. This must be an existing (known) property
						of the ClassDescriptor.
		@param	value	Value of the requested property.
		@param	data	Any data associated with the property.
		@returns		The result of the operation.
	*/
	Result GetProperty( const String& name, String& value, PLMXML_MODELLER_HANDLE& data ) const;
};

//////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

/*! \namespace plmxml_api
    \brief PLM XML SDK generic API namespace.

    plmxml_api namespace includes functionality of PLM XML SDK.
*/
PLMXML_BEGIN_NAMESPACE( plmxml_api )

//! Get build information
/*!
	BuildInfo GetBuildInfo( void )
*/
PLMXML_BUILD_INFO( PLMXML_API )

//////////////////////////////////////////////////////////////////////
//! Loads a set of Handles from a URI or xml fragment. 
/*!
source can either be a URI, such as 

"file:///C:/export/temp.abc#PLMXML(ABC-doc/control/XT-doc)"

in which case the Handles returned will be those of the body or bodies in the specified stream,

or,

"file:///C:/export/temp.abc#PLMXML(ABC-doc/control/XT-doc/body[@BODY_ID='5']/edge[@id='604'])"

in which case the Handle will be that of the specified edge, 

or,

source can be an XML fragment such as

"\<Part id="id42"\>\<Representation format="XT" location="abc.x_t"\>\</Part\>"

in which case the Handle will be that of the Part loaded. The fragment may contain more
than one tree of elements, as in 

"\<Part ...\>\<Part ...\>\<Part ...\>"

in which case the roots of the object trees loaded will be returned.

	@deprecated Replaced by plmxml_api::Load( const String& source, Array<Handle>& loadedHandles, Configuration* options ) in preference.
*/
PLMXML_API Result Load( 
	const String& source,  
	const Configuration& loadOptions,
    Array<Handle>& loadedHandles );

//////////////////////////////////////////////////////////////////////
//! Loads a set of Handles from a URI or xml fragment.
/*!
	@param	source			Can either be a URI, or an XML fragment such as:
									"\<ProductRevisionView id="id42"\>
										\<Representation format="XT" location="abc.x_t"/\>
									\</ProductRevisionView\>"
	@param	loadedHandles	Results of the load operation. 

								If the 'source' is a URI of a PLM XML document this will contain the loaded
								PLM XML document.

								If the 'source' is a URI of the following form:

									"file:///C:/export/temp.abc#PLMXML(ABC-doc/control/XT-doc)"

								the Handles will be those of the body or bodies in the specified stream.

								If the 'source' is a URI of the following form:

									"file:///C:/export/temp.abc#PLMXML(ABC-doc/control/XT-doc/body[@BODY_ID='5']/edge[@id='604'])"

								the Handle will be that of the specified edge.

								If the source is an XML fragment then the Handle will be the root Object in 
								fragment that has been loaded. If more the root Object is contained in the fragment
								the a Handle will be returned for each root.
	@param	options			Optional options to use for the Load operation. If this is NULL or not specified
								then the default options or any global options in scope (as specified by 
								ConfigurationRef) will be used. Options specified to this function take 
								precedence over any global options.
*/
PLMXML_API Result Load( 
	const String& source,  
    Array<Handle>& loadedHandles,
	Configuration* options = NULL );

//////////////////////////////////////////////////////////////////////
//! Loads a PLM XML Document.
/*!
Loads a plmxml stream pointed to by the URI ('uriString' argument). 
Stream will be opened using URI Resolver
Default URI Resolver only supports http:// and file:// streams, for example

\verbatim
http://abc.com/test.xml
file://localhost/c:/temp/test.xml
file:///c:/temp/abc.extxml
file://network/a/b/c.xml
\endverbatim

	@deprecated Use plmxml_api::Load( const String& source, Array<Handle>& loadedHandles, Configuration* options ) in preference.
*/
PLMXML_API Result LoadDocument(    
    const String& uriString,
    const Configuration& LoadOptions,
    Object **pDocument );

//////////////////////////////////////////////////////////////////////
//! Load a multiple Document.
/*!
Loads an plmxml stream which may contain more than one DocumentBase element, e.g.
\<plmxml\> ... \</plmxml\> ... \<plmxml\> ... \</plmxml\>

	@deprecated Use plmxml_api::Load( const String& source, Array<Handle>& loadedHandles, Configuration* options ) in preference.
*/
PLMXML_API Result LoadMultipleDocument( 
	const String& uriString,
	const Configuration& LoadOptions,
	Array<Object*> &pDocuments );

//////////////////////////////////////////////////////////////////////
//! Resolves (loads) a full PLMXMLPointer reference.
/*!
	@deprecated Use plmxml_api::Load( const String& source, Array<Handle>& loadedHandles, Configuration* options ) in preference.
*/
PLMXML_API Result ResolveURI( 
	const String& uriString,  
    Array<Handle>& resolvedHandles );

//////////////////////////////////////////////////////////////////////
//! Converts an Instance based assembly structure to an Occurrence based one.
/*!
	@param	instanceStructure	The assembly structure to convert. Can either be
								an InstanceGraph or StructureRevisionView derived object.
	@param	occurrenceSet		Generated Occurrence based assembly structure.
	@param	options				Optional Configuration options controlling the conversion. 
								If no options are specified then the default options will 
								be used.
	@returns					In addition to the standard result error codes this function 
								can returns the following:

									ErrorCodeInvalidArgument	
									
										If 'instanceStructure' is a NULL reference or of an 
										incorrect type.

									ErrorCodeNotImplemented		
									
										If the 'API/structure_conversion/occurrence_properties'
										option is set to 'all'

	The following Configuration options are supported:
								
	\verbatim
		
	API
		structure_conversion
			
			occurrence_set			- Controls the structure of the resulting returned Objects.

									Allowed Values:

										"list"			- only leaf occurrences are generated and output in the
														array (Default).

										"tree"			- all occurrences are generated and connected into a   
														tree using occurrenceRefs attribute. Occurrences 
														reference the appropriate part using the partRef 
														attribute. For convenience a back-pointer from an 
														Occurrence to the parent Occurrence in the tree will 
														be provided through the parentRef attribute.

										"product_view"	- all occurrences are generated and connected into a 
														tree using occurrenceRefs attribute. A new ProductView 
														is created and returned, all occurrences are added as 
														children of the ProductView and the rootRefs attribute 
														is appropriately set.
			
			overrides				- Controls how Occurrence overrides are taken into account.

									Allowed Values:

										"all"			- all occurrence overrides are taken into account.
														(Default)

										"none"			- no account is taken of any occurrence-specific 
														overrides present in instance assembly.

										"structure"		- only overrides of the structure are considered.

										"property"		- only property overrides are considered.

			occurrence_properties	- Controls the content of the resultant occurrences
					
									Allowed Values:

										"none"			- resulting occurrences do not contain any data 
														implied by the instance structure, they just 
														point back to instance paths (Default)
	
										"all"			- resulting Occurrences contain all data assembled
														from the Instance structure and overrides.

	\endverbatim
*/
PLMXML_API Result CreateOccurrenceSet(
	Object*			instanceStructure,
	Array<Object*>&	occurrenceSet,
	Configuration*	options = NULL );

////////////////////////////////////////////////////////////////////////////////
//! Creates a ProductRevisionView object.
/*!
	CreateProduct creates a ProductRevisionView in a given PLM XML Document,
	given a ProductId and a Revision. It creates a Product related to ProductId
	and a ProductRevision related to Revision if they do not already exist.
	It links some of the attributes of the objects together but does not set the
	\c viewRef attribute of the ProductRevisionView.

	@param document The PLM XML Document in which to create the
		ProductRevisionView and, if they do not already exist, the Product and
		the ProductRevision. By default, objects are created directly under
		document but this behaviour can be overridden by options.
	@param productId The ProductId of the Product. If such a Product does not
		already exist in document, one will be created and its \c productId
		attribute will be set to productId.
	@param revision The revision of the ProductRevision to be used. If such a
		ProductRevision does not already exist in the PLM XML Document, one will
		be created and its \c masterRef attribute will be set to reference the
		Product to be used \& its \c revision attribute will be set to revision.
	@param productRevisionView The ProductRevisionView created and returned. The
		\c revisionRef attribute of productRevisionView will be set to reference
		the ProductRevision to be used.
	@param options An optional Configuration object. By default,
		productRevisionView will be created directly under document. However,
		this behaviour can be changed by setting
		API/create_product/use_instance_graph to true. In this case,
		productRevisionView will be created under the first InstanceGraph under
		the first ProductDef in document. If they do not already exist, they
		will be created. A reference to productRevisionView will be added to the
		\c rootRefs attribute of the InstanceGraph.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateProduct(
	Object*			document,
	const String&	productId,
	const String&	revision,
	Object*&		productRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a ProductRevisionView object.
/*!
	CreateProduct creates a ProductRevisionView in the same PLM XML Document as
	a given Product, given a Revision. It creates a ProductRevision related to
	Revision if it does not already exist. It links some of the attributes of
	the objects together but does not set the \c viewRef attribute of the
	ProductRevisionView.

	@param product The Product to be used.
	@param revision The revision of the ProductRevision to be used. If such a
		ProductRevision does not already exist in the PLM XML Document, one
		will be created and its \c masterRef attribute will be set to reference
		the Product to be used \& its \c revision attribute will be set to
		revision.
	@param productRevisionView The ProductRevisionView created and returned. The
		\c revisionRef attribute of productRevisionView will be set to reference
		the ProductRevision to be used.
	@param options An optional Configuration object. By default,
		productRevisionView will be created directly under the same PLM XML
		Document as product. However, this behaviour can be changed by setting
		API/create_product/use_instance_graph to true. In this case,
		productRevisionView will be created under the first InstanceGraph under
		the first ProductDef in the Document. If they do not already exist, they
		will be created. A reference to productRevisionView will be added to the
		\c rootRefs attribute of the InstanceGraph.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateProduct(
	Object*			product,
	const String&	revision,
	Object*&		productRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a ProductRevisionView object.
/*!
	CreateProduct creates a ProductRevisionView in the same PLM XML Document as
	a given ProductRevision. It links some of the attributes of	the objects
	together but does not set the \c viewRef attribute of the
	ProductRevisionView.

	@param productRevision The ProductRevision to be used. productRevision
		determines the Product to be used.
	@param productRevisionView The ProductRevisionView created and returned. The
		\c revisionRef attribute of productRevisionView will be set to reference
		the ProductRevision to be used.
	@param options An optional Configuration object. By default,
		productRevisionView will be created directly under the same PLM XML
		Document as the Product, which is determined from productRevision.
		However, this behaviour can be changed by setting
		API/create_product/use_instance_graph to true. In this case,
		productRevisionView will be created under the first InstanceGraph under
		the first ProductDef in the Document. If they do not already exist, they
		will be created. A reference to productRevisionView will be added to the
		\c rootRefs attribute of the InstanceGraph.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateProduct(
	Object*			productRevision,
	Object*&		productRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a StructureRevisionView-based object.
/*!
	CreateStructure creates a StructureRevisionView-based object of a given
	sub-class in a given PLM XML Document, given a StructureId and a Revision.
	It creates a Structure-based object related to StructureId and a
	StructureRevision-based object related to Revision if they do not already
	exist. It links some of the attributes of the objects together but does not
	set the \c viewRef attribute of the StructureRevisionView.

	@param document The PLM XML Document in which to create the
		StructureRevisionView-based object and, if they do not already exist,
		the Structure-based object and the StructureRevision-based object. By
		default, objects are created directly under document but this behaviour
		can be overridden by options.
	@param subClass The sub-class of the StructureRevisionView-based object to
		be created, that is \<subClass\>RevisionView. The sub-class of the
		Structure-based object and the StructureRevision-based object to be
		created if they do not already exist, that is \<subClass\> and
		\<subClass\>Revision. subClass may be qualified with a namespace. If no
		namespace is specified, the namespace of the base schema is assumed.
	@param structureId If the sub-class of the Structure-based object to be used
		is a Product, structureId is the productId. Otherwise, structureId is
		the catalogueId. If such a Structure does not already exist in document,
		one will be created and its \c productId or \c catalogueId attribute as
		appropriate will be set to structureId.
	@param revision The revision of the StructureRevision-based object to be
		used. If such a StructureRevision does not already exist in the PLM XML
		Document, one will be created and its \c masterRef attribute will be set
		to reference the Structure-based object to be used \& its \c revision
		attribute will be set to revision.
	@param structureRevisionView The StructureRevisionView-based object created
		and returned. The \c revisionRef attribute of structureRevisionView will
		be set to reference the StructureRevision-based object to be used.
	@param options An optional Configuration object. By default,
		structureRevisionView will be created directly under document. However,
		this behaviour can be changed by setting
		API/create_structure/use_instance_graph to true. In this case,
		structureRevisionView will be created under the first InstanceGraph
		under the first PlantDef, ProcessDef or ProductDef in document. If they
		do not already exist, they will be created. A reference to
		structureRevisionView will be added to the \c rootRefs attribute of the
		InstanceGraph. Note that a MechanismRevisionView cannot be created under
		an InstanceGraph.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateStructure(
	Object*			document,
	const String&	subClass,
	const String&	structureId,
	const String&	revision,
	Object*&		structureRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a StructureRevisionView-based object.
/*!
	CreateStructure creates a StructureRevisionView-based object in the same PLM
	XML Document as a given Structure-based object, given a Revision. It creates
	a StructureRevision-based object related to Revision if it does not already
	exist. It links some of the attributes of the objects together but does not
	set the \c viewRef attribute of the StructureRevisionView.

	@param structure The Structure-based object to be used. structure determines
		the sub-class of the StructureRevisionView-based object to be created
		and the StructureRevision-based object to be created if it does not
		already exist, that is \<subClass\>RevisionView and \<subClass\>Revision
		respectively.
	@param revision The revision of the StructureRevision-based object to be
		used. If such a StructureRevision does not already exist in the PLM XML
		Document, one will be created and its \c masterRef attribute will be set
		to reference the Structure-based object to be used \& its \c revision
		attribute will be set to revision.
	@param structureRevisionView The StructureRevisionView-based object created
		and returned. The \c revisionRef attribute of structureRevisionView will
		be set to reference the StructureRevision-based object to be used.
	@param options An optional Configuration object. By default,
		structureRevisionView will be created directly under the same PLM XML
		Document as structure. However, this behaviour can be changed by setting
		API/create_structure/use_instance_graph to true. In this case,
		structureRevisionView will be created under the first InstanceGraph
		under the first PlantDef, ProcessDef or ProductDef as appropriate in the
		Document. If they do not already exist, they will be created. A
		reference to structureRevisionView will be added to the \c rootRefs
		attribute of the InstanceGraph. Note that a MechanismRevisionView cannot
		be created under an InstanceGraph.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateStructure(
	Object*			structure,
	const String&	revision,
	Object*&		structureRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a StructureRevisionView-based object.
/*!
	CreateStructure creates a StructureRevisionView-based object in the same PLM
	XML Document as a given StructureRevision-based object. It links some of the
	attributes of the objects together but does not set the \c viewRef attribute
	of the StructureRevisionView.

	@param structureRevision The StructureRevision-based object to be used.
		structureRevision determines the Structure-based object to be used and
		the sub-class of the StructureRevisionView-based object to be created,
		that is \<subClass\>RevisionView.
	@param structureRevisionView The StructureRevisionView-based object created
		and returned. The \c revisionRef attribute of structureRevisionView will
		be set to reference the StructureRevision-based object to be used.
	@param options An optional Configuration object. By default,
		structureRevisionView will be created directly under the same PLM XML
		Document as the Structure, which is determined from structureRevision.
		However, this behaviour can be changed by setting
		API/create_structure/use_instance_graph to true. In this case,
		structureRevisionView will be created under the first InstanceGraph
		under the first PlantDef, ProcessDef or ProductDef as appropriate in the
		Document. If they do not already exist, they will be created. A
		reference to structureRevisionView will be added to the \c rootRefs
		attribute of the InstanceGraph. Note that a MechanismRevisionView cannot
		be created under an InstanceGraph.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateStructure(
	Object*			structureRevision,
	Object*&		structureRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a StructureInstance-based object.
/*!
	CreateStructureInstance creates a StructureInstance-based object of one
	StructureRevisionView-based object in another. For example, it creates a
	ProductInstance of one ProductRevisionView representing a piece part or
	sub-assembly in another representing an assembly. Currently, it does not
	check for illegal recursive loops of StructureInstances.

	@param structureRevisionView The StructureRevisionView-based object to be
		instanced. Only the combinations of structureRevisionView and
		assyStructureRevisionView in the table below are compatible. If they are
		incompatible, the operation will fail.
	@param assyStructureRevisionView The StructureRevisionView-based object	in
		which to instance structureRevisionView. Only the combinations of
		structureRevisionView and assyStructureRevisionView in the following
		table are compatible. If they are incompatible, the operation will
		fail...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>assyStructureRevisionView</B></TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>DrawingRevisionView</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>MechanismRevisionView</TD><TD>MechanismRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductRevisionView</TD></TR></TABLE>
		A reference to structureRevisionView will be added to its \c
		instanceRefs attribute.
	@param structureInstance The StructureInstance-based object created and
		returned. The sub-class of the StructureInstance to create is determined
		by the sub-class of structureRevisionView according to the following
		table...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>structureInstance</B></TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ConnectionInstance</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>Instance</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>ConnectionInstance</TD></TR>
	<TR><TD>MechanismRevisionView</TD><TD>MechanismInstance</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>WorkAreaInstance</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessInstance</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductInstance</TD></TR></TABLE>
		The operation will fail if structureRevisionView is of any other
		sub-class. The StructureInstance is created in the same InstanceGraph as
		structureRevisionView. Its \c partRef attribute is set to reference
		structureRevisionView. The reference to structureRevisionView will be
		removed from the \c rootRefs attribute of the InstanceGraph.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateStructureInstance(
	Object*			structureRevisionView,
	Object*			assyStructureRevisionView,
	Object*&		structureInstance,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds a context StructureRevisionView.
/*!
	Finds the context StructureRevisionView-based object of a given
	Instance-based object, Occurrence-based object or ConfigurationView-based
	object.

	@param object The Instance-based object, Occurrence-based object or
		ConfigurationView-based object passed.
	@param structureRevisionView The StructureRevisionView-based object that
		provides the context for object. The StructureRevisionView found must be
		of a compatible sub-class to object according to the following table...
	<TABLE><TR><TD><B>object</B></TD><TD><B>structureRevisionView</B></TD></TR>
	<TR><TD>ConnectionInstance</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>ConnectionInstance</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>ConnectionInstance</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ConnectionInstance</TD><TD>ProductRevisionView</TD></TR>
	<TR><TD>Instance</TD><TD>DrawingRevisionView</TD></TR>
	<TR><TD>Instance</TD><TD>ProductRevisionView</TD></TR>
	<TR><TD>MechanismInstance</TD><TD>MechanismRevisionView</TD></TR>
	<TR><TD>ProcessInstance</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>ProductInstance</TD><TD>ProductRevisionView</TD></TR>
	<TR><TD>WorkAreaInstance</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>WorkAreaInstance</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>MechanismOccurrence</TD><TD>MechanismRevisionView</TD></TR>
	<TR><TD>Occurrence</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>Occurrence</TD><TD>DrawingRevisionView</TD></TR>
	<TR><TD>Occurrence</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>Occurrence</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>Occurrence</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>Occurrence</TD><TD>ProductRevisionView</TD></TR>
	<TR><TD>ProcessOccurrence</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>WorkAreaOccurrence</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>WorkAreaOccurrence</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>PlantView</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ProcessView</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>ProductView</TD><TD>ProductRevisionView</TD></TR></TABLE>
		If object is an Instance-based object, structureRevisionView is the
		StructureRevisionView-based object that references the Instance by any
		member of its \c instanceRefs attribute. If object is an
		Occurrence-based object, structureRevisionView is the context
		StructureRevisionView of the Instance referenced by the first member of
		the \c instanceRefs attribute of the Occurrence, if \c instanceRefs is
		present. If \c instanceRefs is absent, structureRevisionView is the
		StructureRevisionView referenced by the \c partRef attribute of the
		Occurrence. If object is a ConfigurationView-based object,
		structureRevisionView is the context StructureRevisionView of the
		Occurrences referenced by all members of the \c rootRefs attribute of
		the ConfigurationView.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed. If object is a
		deprecated dummy Instance, an ErrorCodeOK with ErrorSeverityWarning is
		returned.
*/
PLMXML_API Result GetContextStructure(
	Object*			object,
	Object*&		structureRevisionView,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds ConfigurationViews.
/*!
	Finds all the ConfigurationView-based objects of a
	StructureRevisionView-based object. For example, finds all the ProductViews
	of a ProductRevisionView.

	@param structureRevisionView The StructureRevisionView-based object passed.
	@param structureViews The set of ConfigurationView-based objects returned. A
		ConfigurationView appears in the set if an Occurrence-based object in
		the ConfigurationView has the first member of its \c instanceRefs
		attribute referencing an Instance-based object that is instanced in
		structureRevisionView, if \c instanceRefs is present, or its \c partRef
		attribute referencing structureRevisionView, if \c instanceRefs is
		absent. The ConfigurationViews found will be sub-class compatible with
		structureRevisionView, according to the following table...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>structureViews</B></TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>PlantView</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessView</TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ProductView</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>ProductView</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>ProductView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductView</TD></TR></TABLE>
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetStructureViews(
	Object*			structureRevisionView,
	Array<Object*>&	structureViews,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds root StructureRevisionViews.
/*!
	Finds the StructureRevisionView-based objects that are not instanced in
	another StructureRevisionView-based object.

	@param document The Document to search.
	@param roots The set of StructureRevisionView-based objects that are not
		instanced in another StructureRevisionView. The set includes root
		assemblies and stand-alone piece parts. By default, it includes all
		sub-classes of StructureRevisionView.
	@param options An optional Configuration object. By default, the returned
		set includes all sub-classes of StructureRevisionView. However, this
		behaviour can be changed by setting API/get_structure_roots/class_name
		to the class-name of a sub-class of StructureRevisionView. In this case,
		the search is restricted to roots of that sub-class. For example,
		setting API/get_structure_roots/class_name to "ProductRevisionView" will
		return only ProductRevisionView roots.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetStructureRoots(
	Object*			document,
	Array<Object*>&	roots,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds StructureRevisions.
/*!
	Finds all the StructureRevision-based objects related to a Structure-based
	object.

	@param structure The Structure-based object passed.
	@param structureRevisions The set of StructureRevision-based objects that
		have their \c masterRef attributes referencing structure. The
		StructureRevisions found will be of the same sub-class as structure,
		that is \<sub-class\>Revision.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetRevisions(
	Object*			structure,
	Array<Object*>&	structureRevisions,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds StructureRevisionViews.
/*!
	Finds all the StructureRevisionView-based objects related to a
	StructureRevision-based object.

	@param structureRevision The Structure-based object passed.
	@param structureRevisionViews The set of StructureRevisionView-based objects
		that have their \c revisionRef attributes referencing structureRevision.
		The StructureRevisionViews found will be of the same sub-class as
		structureRevision, that is \<sub-class\>RevisionView. If
		structureRevision is a WorkAreaRevision, the StructureRevisionViews
		found will be PlantRevisionViews.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetRevisionViews(
	Object*			structureRevision,
	Array<Object*>&	structureRevisionViews,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds parent StructureRevisionViews.
/*!
	Finds the StructureRevisionView-based objects that use a given
	StructureRevisionView-based object. For example, finds all the assembly
	ProductRevisionViews that use a given ProductRevisionView piece part or
	sub-assembly.

	@param structureRevisionView The StructureRevisionView-based object passed.
	@param parents The set of StructureRevisionView-based objects that instance
		(via unspecified Instance-based objects) structureRevisionView. If
		structureRevisionView is a root assembly or it represents a
		stand-alone piece part, the empty set is returned. The
		StructureRevisionViews found will be sub-class compatible with
		structureRevisionView, according to the following table...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>users</B></TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>DrawingRevisionView</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>MechanismRevisionView</TD><TD>MechanismRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductRevisionView</TD></TR></TABLE>
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetStructureParents(
	Object*			structureRevisionView,
	Array<Object*>&	parents,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds Instances of a StructureRevisionView.
/*!
	Finds the Instance-based objects that instance a given
	StructureRevisionView-based object.

	@param structureRevisionView The StructureRevisionView-based object passed.
	@param instances The set of Instance-based objects that instance
		structureRevisionView. The Instances found must be of a compatible
		sub-class to structureRevisionView according to the following table...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>instancers</B></TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ConnectionInstance</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>Instance</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>ConnectionInstance</TD></TR>
	<TR><TD>MechanismRevisionView</TD><TD>MechanismInstance</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>PlantInstance</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessInstance</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>Instance</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductInstance</TD></TR></TABLE>
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetStructureInstances(
	Object*			structureRevisionView,
	Array<Object*>&	instances,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Determines if a StructureRevisionView represents an assembly.
/*!
	Returns TRUE if a given StructureRevisionView-based object is an assembly of
	one or more other StructureRevisionViews and FALSE otherwise.
	
	@param structureRevisionView The StructureRevisionView-based object passed.
	@param isAssembly isAssembly is set to TRUE if structureRevisionView
		instances an Instance-based object of another StructureRevisionView of
		the same or a compatible sub-class according to the following table...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>Instanced StructureRevisionView</B></TD><TD><B>isAssembly</B></TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ConnectionRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>FlowConnectionRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>DrawingRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>FlowConnectionRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>MechanismRevisionView</TD><TD>MechanismRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>ConnectionRevisionView</TD><TD>FALSE</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>FlowConnectionRevisionView</TD><TD>FALSE</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>PlantRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>PlantRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessRevisionView</TD><TD>TRUE</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ConnectionRevisionView</TD><TD>FALSE</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>FlowConnectionRevisionView</TD><TD>FALSE</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductRevisionView</TD><TD>TRUE</TD></TR></TABLE>
		The Instance-based object must also be compatible with the instanced
		StructureRevisionView according to the following table...
	<TABLE><TR><TD><B>structureRevisionView</B></TD><TD><B>Instance</B></TD><TD><B>Instanced StructureRevisionView</B></TD></TR>
	<TR><TD>ConnectionRevisionView</TD><TD>ConnectionInstance</TD><TD>ConnectionRevisionView</TD></TR>
	<TR><TD>DrawingRevisionView</TD><TD>Instance</TD><TD>DrawingRevisionView</TD></TR>
	<TR><TD>FlowConnectionRevisionView</TD><TD>ConnectionInstance</TD><TD>FlowConnectionRevisionView</TD></TR>
	<TR><TD>MechanismRevisionView</TD><TD>MechanismInstance</TD><TD>MechanismRevisionView</TD></TR>
	<TR><TD>PlantRevisionView</TD><TD>PlantInstance</TD><TD>PlantRevisionView</TD></TR>
	<TR><TD>ProcessRevisionView</TD><TD>ProcessInstance</TD><TD>ProcessRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>Instance</TD><TD>ProductRevisionView</TD></TR>
	<TR><TD>ProductRevisionView</TD><TD>ProductInstance</TD><TD>ProductRevisionView</TD></TR></TABLE>
		isAssembly is set to FALSE otherwise.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result IsAssembly(
	Object*			structureRevisionView,
	logical&		isAssembly,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates a ProductView to represent an Arrangement.
/*!
	Creates a ProductView to represent an Arrangement of an assembly or a
	sub-assembly. Sets its \c usage attribute to "arrangement" and its \c
	definition attribute to "overlay". Creates an Occurrence under the
	ProductView. Sets the \c rootRefs attribute of the ProductView to reference
	the Occurrence. Sets the \c partRef attribute of the Occurrence to reference
	the assembly or the sub-assembly.

	@param name The name of the ProductView to be created. Its \c name attribute
		will be set to name.
	@param productRevisionView If productRevisionView is a piece part, the
		operation will fail. Otherwise, the \c partRef attribute of the created
		Occurrence will be set to reference productRevisionView.
	@param arrangement The ProductView that represents the Arrangement created
		and returned. If productRevisionView lies directly under a PLM XML
		Document, arrangement is created directly under the PLM XML Document. If
		productRevisionView lies under an InstanceGraph sub-element, arrangement
		will be created under the ProductDef sub-element, under which the
		InstanceGraph lies.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreateArrangement(
	const String&	name,
	Object*			productRevisionView,
	Object*&		arrangement,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Sets an Arrangement of an assembly to instance a particular Arrangement of a sub-assembly.
/*!
	Sets an Arrangement of an assembly to instance a particular Arrangement of a
	sub-assembly by creating an Occurrence under the ProductView that represents
	the Arrangement of the assembly.

	@param assyArrangement The ProductView that represents the Arrangement of
		the assembly. If its \c usage attribute is not set to "arrangement" or
		its \c definition attribute to "overlay", the operation will fail.
	@param instance An instance of an immediate sub-assembly of the assembly. If
		it is not one of an immediate sub-assembly, the operation will fail.
	@param subAssyArrangement The ProductView that represents the Arrangement of
		the immediate sub-assembly. If it is not an immediate sub-assembly, the
		operation will fail. If its \c usage attribute is not set to
		"arrangement" or its \c definition attribute to "overlay", the operation
		will fail.
	@param occurrence The Occurrence created and returned. The \c instanceRefs
		attribute of occurrence will be set to reference instance and its \c
		productViewRef attribute will be set to reference the ProductView that
		represents the Arrangement of the sub-assembly. The returned Occurrence
		can be used to override the default product structure in the usual way.
		For example, when creating different Arrangements of assyArrangement,
		which could be used in Arrangements at higher levels of the product
		structure.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result SetInstanceArrangement(
	Object*			assyArrangement,
	Object*			instance,
	Object*			subAssyArrangement,
	Object*&		occurrence,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates PMI.
/*!
	Creates a 3D Annotation and a 3D Annotation Display of a given sub-class
	directly under a PLM XML Document. Optionally creates an Ann3DInstanceGroup
	under the PLM XML Document or an InstanceGraph. Creates an Ann3DInstance
	under the PLM XML Document, the InstanceGraph or the created
	Ann3DInstanceGroup.

	@param subClass The sub-class of 3D Annotation and 3D Annotation Display to
		create according to the following table...
	<TABLE><TR><TD><B>subClass</B></TD><TD><B>3D Annotation</B></TD><TD><B>3D Annotation Display</B></TD></TR>
	<TR><TD>AttributeNote</TD><TD>AttributeNote</TD><TD>AttributeNote</TD></TR>
	<TR><TD>Ann3DeMarking</TD><TD>Ann3DeMarking</TD><TD>Ann3DeMarkingDisplay</TD></TR>
	<TR><TD>Ann3DOrganisation</TD><TD>Ann3DOrganisation</TD><TD>Ann3DOrganisationDisplay</TD></TR>
	<TR><TD>Balloon</TD><TD>Balloon</TD><TD>BalloonDisplay</TD></TR>
	<TR><TD>BundleDressingNote</TD><TD>BundleDressingNote</TD><TD>BundleDressingNoteDisplay</TD></TR>
	<TR><TD>CircleCentre</TD><TD>CircleCentre</TD><TD>CircleCentreDisplay</TD></TR>
	<TR><TD>CoordinateNote</TD><TD>CoordinateNote</TD><TD>CoordinateNoteDisplay</TD></TR>
	<TR><TD>Crosshatch</TD><TD>Crosshatch</TD><TD>CrosshatchDisplay</TD></TR>
	<TR><TD>CuttingPlaneSymbol</TD><TD>CuttingPlaneSymbol</TD><TD>CuttingPlaneSymbolDisplay</TD></TR>
	<TR><TD>DatumFeatureSymbol</TD><TD>DatumFeatureSymbol</TD><TD>DatumFeatureSymbolDisplay</TD></TR>
	<TR><TD>DatumTarget</TD><TD>DatumTarget</TD><TD>DatumTargetDisplay</TD></TR>
	<TR><TD>Dimension</TD><TD>Dimension</TD><TD>DimensionDisplay</TD></TR>
	<TR><TD>Fastener</TD><TD>Fastener</TD><TD>FastenerDisplay</TD></TR>
	<TR><TD>FeatureControlFrame</TD><TD>FeatureControlFrame</TD><TD>FeatureControlFrameDisplay</TD></TR>
	<TR><TD>LineWeld</TD><TD>LineWeld</TD><TD>LineWeldDisplay</TD></TR>
	<TR><TD>Locator</TD><TD>Locator</TD><TD>LocatorDisplay</TD></TR>
	<TR><TD>MaterialSpec</TD><TD>MaterialSpec</TD><TD>MaterialSpecDisplay</TD></TR>
	<TR><TD>MeasurementPoint</TD><TD>MeasurementPoint</TD><TD>MeasurementPointDisplay</TD></TR>
	<TR><TD>Note</TD><TD>Note</TD><TD>NoteDisplay</TD></TR>
	<TR><TD>PartSpec</TD><TD>PartSpec</TD><TD>PartSpecDisplay</TD></TR>
	<TR><TD>ProcessSpec</TD><TD>ProcessSpec</TD><TD>ProcessSpecDisplay</TD></TR>
	<TR><TD>SpotWeld</TD><TD>SpotWeld</TD><TD>SpotWeldDisplay</TD></TR>
	<TR><TD>SurfaceFinish</TD><TD>SurfaceFinish</TD><TD>SurfaceFinishDisplay</TD></TR>
	<TR><TD>UserDefinedSymbol</TD><TD>UserDefinedSymbol</TD><TD>UserDefinedSymbolDisplay</TD></TR></TABLE>
	@param owner The owner of the PMI. If owner is a StructureRevisionView,
		ann3DInstance will normally be created under the owner of the
		StructureRevisionView but the default behaviour can be overridden by
		options. A reference to ann3DInstance will be added to the \c
		gdeInstanceRefs attribute of the StructureRevisionView. If owner is an
		Ann3DInstanceGroup, ann3DInstance will always be created under the
		Ann3DInstanceGroup.
	@param ann3DInstance The Ann3DInstance created and returned. If owner is a
		StructureRevisionView, ann3DInstance will normally be created under the
		owner of the StructureRevisionView but the default behaviour can be
		overridden by options. If owner is an Ann3DInstanceGroup, ann3DInstance
		will always be created under the Ann3DInstanceGroup. The \c instanceRefs
		attribute of ann3DInstance will be set to reference the created 3D
		Annotation and its \c displayRef attribute will be set to reference the
		created 3D Annotation Display.
	@param options An optional Configuration object. If owner is an
		Ann3DInstanceGroup, options will be ignored. If owner is a
		StructureRevisionView, ann3DInstance will normally be created under the
		owner of the StructureRevisionView. However, this behaviour can be
		changed by setting API/create_pmi/use_ann3d_instance_group to true. In
		this case, an Ann3DInstanceGroup will be created under the owner of the
		StructureRevisionView, ann3DInstance will be created under the
		Ann3DInstanceGroup, and a reference to the Ann3DInstanceGroup will be
		added to the \c gdeInstanceRefs attribute of the StructureRevisionView.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreatePMI(
	const String&	subClass,
	Object*			owner,
	Object*&		ann3DInstance,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Creates PMI.
/*!
	Creates a 3D Annotation or a 3D Annotation Display of the same sub-class as
	the given 3D Annotation Display or 3D Annotation directly under a PLM XML
	Document. Optionally creates an Ann3DInstanceGroup under the PLM XML
	Document or an InstanceGraph. Creates an Ann3DInstance under the PLM XML
	Document, the InstanceGraph or the created Ann3DInstanceGroup.

	@param ann3D If both ann3D and ann3DDisplay are NULL, the operation will
		fail. If ann3D is incompatible with ann3DDisplay the operation will
		fail. If ann3D is NULL, a 3D Annotation compatible with ann3DDisplay
		according to the following table will be created directly under the same
		PLM XML Document as ann3DDisplay...
	<TABLE><TR><TD><B>ann3D</B></TD><TD><B>ann3DDisplay</B></TD></TR>
	<TR><TD>AttributeNote</TD><TD>AttributeNoteDisplay</TD></TR>
	<TR><TD>Ann3DeMarking</TD><TD>Ann3DeMarkingDisplay</TD></TR>
	<TR><TD>Ann3DOrganisation</TD><TD>Ann3DOrganisationDisplay</TD></TR>
	<TR><TD>Balloon</TD><TD>BalloonDisplay</TD></TR>
	<TR><TD>BundleDressingNote</TD><TD>BundleDressingNoteDisplay</TD></TR>
	<TR><TD>CircleCentre</TD><TD>CircleCentreDisplay</TD></TR>
	<TR><TD>CoordinateNote</TD><TD>CoordinateNoteDisplay</TD></TR>
	<TR><TD>Crosshatch</TD><TD>CrosshatchDisplay</TD></TR>
	<TR><TD>CuttingPlaneSymbol</TD><TD>CuttingPlaneSymbolDisplay</TD></TR>
	<TR><TD>DatumFeatureSymbol</TD><TD>DatumFeatureSymbolDisplay</TD></TR>
	<TR><TD>DatumTarget</TD><TD>DatumTargetDisplay</TD></TR>
	<TR><TD>Dimension</TD><TD>DimensionDisplay</TD></TR>
	<TR><TD>Fastener</TD><TD>FastenerDisplay</TD></TR>
	<TR><TD>FeatureControlFrame</TD><TD>FeatureControlFrameDisplay</TD></TR>
	<TR><TD>LineWeld</TD><TD>LineWeldDisplay</TD></TR>
	<TR><TD>Locator</TD><TD>LocatorDisplay</TD></TR>
	<TR><TD>MaterialSpec</TD><TD>MaterialSpecDisplay</TD></TR>
	<TR><TD>MeasurementPoint</TD><TD>MeasurementPointDisplay</TD></TR>
	<TR><TD>Note</TD><TD>NoteDisplay</TD></TR>
	<TR><TD>PartSpec</TD><TD>PartSpecDisplay</TD></TR>
	<TR><TD>ProcessSpec</TD><TD>ProcessSpecDisplay</TD></TR>
	<TR><TD>SpotWeld</TD><TD>SpotWeldDisplay</TD></TR>
	<TR><TD>SurfaceFinish</TD><TD>SurfaceFinishDisplay</TD></TR>
	<TR><TD>UserDefinedSymbol</TD><TD>UserDefinedSymbolDisplay</TD></TR></TABLE>
	@param ann3DDisplay If both ann3D and ann3DDisplay are NULL, the operation
		will fail. If ann3DDisplay is incompatible with ann3D the operation will
		fail. If ann3DDisplay is NULL, a 3D Annotation Display compatible with
		ann3D according the above table will be created directly under the same
		PLM XML Document as ann3D.
	@param owner The owner of the PMI. If owner is a StructureRevisionView,
		ann3DInstance will normally be created under the owner of the
		StructureRevisionView but the default behaviour can be overridden by
		options. A reference to ann3DInstance will be added to the \c
		gdeInstanceRefs attribute of the StructureRevisionView. If owner is an
		Ann3DInstanceGroup, ann3DInstance will always be created under the
		Ann3DInstanceGroup.
	@param ann3DInstance The Ann3DInstance created and returned. If owner is a
		StructureRevisionView, ann3DInstance will normally be created under the
		owner of the StructureRevisionView but the default behaviour can be
		overridden by options. If owner is an Ann3DInstanceGroup, ann3DInstance
		will always be created under the Ann3DInstanceGroup. The \c instanceRefs
		attribute of ann3DInstance will be set to reference the given or created
		3D Annotation and its \c displayRef attribute will be set to reference
		the given or created 3D Annotation Display.
	@param options An optional Configuration object. If owner is an
		Ann3DInstanceGroup, options will be ignored. If owner is a
		StructureRevisionView, ann3DInstance will normally be created under the
		owner of the StructureRevisionView. However, this behaviour can be
		changed by setting API/create_pmi/use_ann3d_instance_group to true. In
		this case, an Ann3DInstanceGroup will be created under the owner of the
		StructureRevisionView, ann3DInstance will be created under the
		Ann3DInstanceGroup, and a reference to the Ann3DInstanceGroup will be
		added to the \c gdeInstanceRefs attribute of the StructureRevisionView.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result CreatePMI(
	Object*&		ann3D,
	Object*&		ann3DDisplay,
	Object*			owner,
	Object*&		ann3DInstance,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Gets PMI.
/*!
	Finds all the Ann3DInstances referenced by a given StructureRevisionView.
	The Ann3DInstances may be referenced either directly or indirectly via
	Ann3DInstanceGroups.

	@param structureRevisionView The StructureRevisionView passed.
	@param ann3DInstances The set of Ann3DInstances returned, which is the union
		of...
	<UL><LI>The set of Ann3DInstances referenced by the \c gdeInstanceRefs attribute of structureRevisionView.</LI>
	<LI>The set of Ann3DInstances under any Ann3DInstanceGroups referenced by the \c gdeInstanceRefs attribute of structureRevisionView.</LI></UL>
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result GetPMI(
	Object*			structureRevisionView,
	Array<Object*>&	ann3DInstances,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
class RepresentationsImpl;

////////////////////////////////////////////////////////////////////////////////
//! Representations class.
/*!
	Holds information about a set of effective Representations and their
	effective CompoundReps.
*/
class PLMXML_API Representations
{
public:
//! Constructor
	Representations();

//! Destructor
	~Representations();

//! Returns the set of effective Representations.
/*!
	@param representations The set of Representation objects that are effective
		for this Representations object.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
	Result GetRepresentations(Array<Object*>& representations) const;

//! Returns the effective CompoundReps for a given Representation.
/*!
	@param representation The Representation object for which to get the set of
		effective CompoundRep objects.
	@param compoundReps The set of CompoundRep objects that are effective for
		representation in this Representations object.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
	Result GetCompoundReps(Object* representation, Array<Object*>& compoundReps) const;

//! Returns the implementation read only.
	RepresentationsImpl *GetImplementation() const;

private:
//! Implementation
	RepresentationsImpl *m_pImpl;

//! Copy constructor
    Representations(const Representations&);

//! Assignment operator
    Representations& operator =(const Representations&);
};

////////////////////////////////////////////////////////////////////////////////
//! Finds Representations.
/*!
	Finds the set of effective Representations and their effective CompoundReps
	of a given Occurrence-based object, Instance-based object or
	ProductRevisionView.

	The set of Representations of an object at a given level in the structure is
	the union of the Representation sub-elements under the object and those
	referenced by its \c representationRef attribute. If an object at a given
	level in the structure has no Representations, its effective Representations
	are obtained from the object at the next level.

	The effective Representations of an object and their effective CompoundReps
	at a given level in the structure differ from the actual Representations and
	their actual CompoundReps because of the following overriding rules...

	If a lower level object in the structure has no Representation with a \c
	baseRef attribute and no Representation with a CompoundRep with a \c baseRef
	attribute, the set of Representations on the lower level object overrides
	the set on the higher level.

	If a lower level object in the structure has a Representation with a \c
	baseRef attribute or a Representation with a CompoundRep with a \c baseRef
	attribute, the set of Representations from the higher level object is
	inherited. The Representations or CompoundReps referenced by any \c baseRef
	attributes are replaced with the referencing Representations or
	CompoundReps. Any Representations or CompoundReps without \c baseRef
	attributes are discarded.

	If a lower level object has both a Representation with a \c baseRef
	attribute and a CompoundRep with a \c baseRef attribute, the Representation
	referenced by the \c baseRef attribute is replaced in preference to the
	CompoundRep. This is equivalent to saying the CompoundRep referenced by the
	\c baseRef attribute is replaced first and then overwritten by the
	Representation.

	These overriding rules and the resulting effective structure are illustrated
	in the following diagram. The actual sub-elements are shown by solid arrows
	and the effective sub-elements are shown by dotted arrows...

	\image html representations.gif

	The set of effective Representations will be represented by a set of
	pointers to the real Representations in an object of a new Representations
	class. (See the Representations Class section.) The effective CompoundReps
	of each effective Representation will be represented by a set of pointers to
	the real CompoundReps.

	@param object The ProductRevisionView, Instance-based object or
		Occurrence-based object passed.
	@param representations A Representations object (see the Representations
		Class section) that represents the set of effective Representations of
		object and their effective CompoundReps.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result ResolveRepresentations(
	Object*				object,
	Representations&	representations,
	Configuration*		options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds a Transform as a Transf object.
/*!
	Finds the effective transform of a given CompoundRep, Representation,
	Occurrence-based object or Instance-based object. The effective transform
	returned is represented as a Transf object.

	Any Transform sub-element of an object at a given level in the structure
	will override any Transform referenced by the object's \c transformRef
	attribute.

	If both a CompoundRep and its parent Representation have Transforms...
	<UL><LI>Calling ResolveTransform on the CompoundRep returns the effective
	transform obtained from the compound of the two Transforms.</LI>
	<LI>Calling ResolveTransform on the Representation returns the effective
	transform obtained from the Transform on the Representation.</LI></UL>

	If only one of the CompoundRep and its parent Representation has a Transform...
	<UL><LI>Calling ResolveTransform on the CompoundRep returns the effective
	transform obtained from the Transform.</LI>
	<LI>Calling ResolveTransform on the Representation returns the effective
	transform obtained from the Transform, if it is on the Representation.</LI>
	<LI>Calling ResolveTransform on the Representation returns the identity
	transform, if it is on the CompoundRep.</LI></UL>

	If neither the CompoundRep nor its parent Representation has a Transform,
	calling ResolveTransform on either the CompoundRep or the Representation
	returns the identity transform because Representations can be shared among
	several objects so a unique object at the next highest level in the
	structure does not exist.

	If an Occurrence-based object has a Transform, calling ResolveTransform on
	the Occurrence returns the effective transform obtained from the Transform.

	If an Occurrence-Based object does not have a Transform, calling
	ResolveTransform on the Occurrence returns the effective transform obtained
	from the compound of the Transforms of the Instance-based objects that
	constitute the path through the structure to the Occurrence.

	If an Instance-based object has a Transform, calling ResolveTransform on the
	Instance returns the effective transform obtained from the Transform.

	If an Instance-based object does not have a Transform, calling the
	ResolveTransform on the Instance returns the identity transform.

	@param object The Instance-based object, Occurrence-based object,
		Representation or CompoundRep passed.
	@param transf A Transf object passed. transf is populated with information
		obtained from a real Transform, the compound of several real Transforms
		or the identity transform.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result ResolveTransform(
	Object*			object,
	Transf&			transf,
	Configuration*	options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds an effective transform as a Transf object.
/*!
	Finds the effective transform of a given virtual occurrence. The effective
	transform returned is represented as a Transf object.

	Any Transform sub-element of an object at a given level in the structure
	will override any Transform referenced by the object's \c transformRef
	attribute.

	Calling ResolveTransform on a virtual occurrence returns the effective
	transform obtained from the compound of the Transforms of the Instance-based
	objects that constitute the path through the structure to the virtual
	occurrence.
	
	@param instances A list of Instance-based objects that defines the path
		through the structure to a virtual occurrence.
	@param transf A Transf object passed. transf is populated with information
		obtained from the compound of the real Transforms of instances or the
		identity transform.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result ResolveTransform(
	const Array<Object*>&	instances,
	Transf&					transf,
	Configuration*			options = NULL);

////////////////////////////////////////////////////////////////////////////////
//! Finds a Property.
/*!
	Finds an effective property of a given RepresentationEntity,
	Occurrence-based object, Instance-based object, StructureRevisionView-based
	object, StructureRevision-based object or Structure-based object.

	The function resolves only properties represented by elements derived from
	the Property element. It does not resolve properties represented by the
	Material element or sub-elements of a MassProperties element.

	The value of any Property-based sub-element (of any PropertyGroup
	sub-element) of an object at a given level in the structure will override
	the value of any Property-based element referenced by the object's \c
	propertyRefs attribute. If an object at a given level in the structure has
	no property of the given name, its effective property is obtained from the
	object at the next level.

	@param object The Structure-based, StructureRevision-based,
		StructureRevisionView-based, Instance-based, Occurrence-based object or
		RepresentationEntity passed.
	@param name The name of the property to be resolved, which must be
		represented by an element derived from the Property element. Currently,
		valid names are...
	<TABLE><TR><TD>BendRadius</TD></TR>
	<TR><TD>CentreOfMass</TD></TR>
	<TR><TD>Colour</TD></TR>
	<TR><TD>CompatibleWireSize</TD></TR>
	<TR><TD>CoordinateExtent</TD></TR>
	<TR><TD>Copyright</TD></TR>
	<TR><TD>CrossSectionalArea</TD></TR>
	<TR><TD>Density</TD></TR>
	<TR><TD>DisplayPreferences</TD></TR>
	<TR><TD>Gravity</TD></TR>
	<TR><TD>Inertia</TD></TR>
	<TR><TD>InitialVelocity</TD></TR>
	<TR><TD>JointAccelerationLimit</TD></TR>
	<TR><TD>JointLimits</TD></TR>
	<TR><TD>JointVelocityLimit</TD></TR>
	<TR><TD>LengthProperty</TD></TR>
	<TR><TD>MassProperty</TD></TR>
	<TR><TD>MaterialSpecification</TD></TR>
	<TR><TD>ModulusOfElasticity</TD></TR>
	<TR><TD>OutsideDiameter</TD></TR>
	<TR><TD>PoissonsRatio</TD></TR>
	<TR><TD>RatedCurrent</TD></TR>
	<TR><TD>RatedPower</TD></TR>
	<TR><TD>RatedVoltage</TD></TR>
	<TR><TD>SpecificHeatCapacity</TD></TR>
	<TR><TD>SurfaceArea</TD></TR>
	<TR><TD>Temperature</TD></TR>
	<TR><TD>ThermalConductivity</TD></TR>
	<TR><TD>ThermalExpansionCoefficient</TD></TR>
	<TR><TD>UltimateElongation</TD></TR>
	<TR><TD>UltimateStress</TD></TR>
	<TR><TD>Visibility</TD></TR>
	<TR><TD>Volume</TD></TR>
	<TR><TD>WireGauge</TD></TR>
	<TR><TD>YieldStress</TD></TR></TABLE>
	@param context Occurrence or Instance if the object is RepresentationEntity. 
	@param property The existing Property-based object returned.
	@param options An optional Configuration object. Currently no configuration
		options are supported for this function.
	@returns A Result object indicating the success or failure of the operation,
		either ErrorCodeInvalidArgument or ErrorCodeFailed.
*/
PLMXML_API Result ResolveProperty(
	Object*			object,
	const String&	name,
	Object*			context,
	Object*&		property,
	Configuration*	options = NULL);

//////////////////////////////////////////////////////////////////////
//! Initialise the SDK.
/*!
	@deprecated Replaced by plmxml_api::Initialise( int nPlugins, char** pluginNames, int nOptions, char** options, AllocatorBase* pAlloc, DeAllocatorBase* pDealloc ) in preference.
*/
PLMXML_API ErrorCode Initialise( 
	int nPlugins,
	char** pluginNames,
	AllocatorBase* pAlloc,
	DeAllocatorBase* pDealloc );

//! Initialise the SDK.
/*!
	This function should be called by the user prior to use of the PLM
	XML SDK. 
	
	It is recommended that the call to 'Initialise' should be made only
	once, by the owning thread before the start of a PLM XML session. 
	Calling 'Initialise' more than once is supported but there are the 
	following restrictions on what can be done during the initial and 
	subsequent calls:

		Adapters and other extensions can be loaded during any call to 
		'Initialise'. 
		
		Serialisation can be enabled during any call but cannot be turned 
		off except by a call to 'Terminate'.

		Custom memory handlers can only be registered during the first
		call to 'Initialise'.

	'Initialise' can be called after a 'Terminate' call in which case it
	is treated as if it were the first call to 'Initialise'
	
	When using this function and the SDK with custom memory handlers
	it is very important not to allocate any memory through the SDK 
	until after the 'Initialise' function has been called as this would 
	cause a mismatch between the mechanisms for allocating and
	deallocating that storage. This includes using any SDK API objects 
	such as strings, arrays, streams, etc.
  
	The function supports pre-loading of SDK adapters (plug-ins) and 
	schema extensions via 'nPlugins' and 'pluginNames' arguments.

	Names of plug-ins or schemas to be loaded can be provided as
	platform independent strings i.e. without any preceding system 
	prefix and without the filename suffix. The SDK will internally 
	ensure that the correct platform dependent plug-in name is used.   
	For example, to load the plmxmlAdapterXT.dll library the string
	'plmxmlAdapterXT' is the string that should be passed in.

	It is also possible to pass plug-in and schema names as platform
	dependent absolute or relative pathnames, for example 
	'c:\\plmxml\\adapters\\plmxmlAdapterXT.dll' or 
	'..\\schemas\\plmxmlAnnotationSchema.xsd'. The toolkit will use 
	the system path or library search path to resolve relative 
	pathnames of shared libraries. But, system paths will not be used 
	for schema ('.xsd') loading.

	During a call to Initialise all Adapters obtained by the SDK will
	have an PLMXML_OP_ADAPTER_INITIALISE operation called against it. 
	Each Adapter can choose to respond to this operation by performing 
	Adapter specific initialisation. A call to Terminate will result 
	in the matching PLMXML_OP_ADAPTER_TERMINATE operation being called.

	The function supports the setting of session wide options via
	'nOptions' and 'options' arguments. These options are valid for 
	the scope of a call to a pair of Initialise/Terminate calls unless
	explicitly overriden for specific functions through the use of a 
	Configuration option.

	The options broadly follow the same structure as those for the 
	Configuration options but with the following structure:

	&lt;option_level1&gt;/&lt;option_level2&gt;=&lt;option_value&gt;
	
	e.g.
		serialise=true
		serialise/threshold=1000

	At the moment the following options are supported:
    
    <b>Multithreading options</b>

    The SDK has support for Multithreading. Multithreading is turned on by a call to the Initialise with the 
    config option "multithreading" supplied. Turning on Multithreading enables the SDK to be used in multiple
    threads in a thread safe fashion. 
    
    Different areas of the SDK have different mulithreading capabilities. 
    Loading, Traversal and Query actions are able to work in many threads with the same or different source 
    documents. Saving can be used in multiples threads if the destination document is unique. 
    Creating and Modification can only be done in a single thread. 
    
    Some classes of the SDK are not supported in multithreading scenarios. These are ConfigRef and URIResolverRef.

    \verbatim

	multithreading					- Whether multithreading is enabled
										"true"	- multithreading is enabled
										"false"	- multithreading is not enabled (default).
	\endverbatim

	<b>Scalability options</b>

	The memory usage behaviour of the SDK when loading and constructing large document models can be controlled.
	An option can be used to 'serialise' data out of memory to an alternate location when it it not being 
	used (and to subsequently load in the data when it is required). This can be used to reduce the amount 
	of memory used by the SDK.

	\verbatim

	serialise					- Whether serialisation of data should occur
										"true"	- Serialisation of data will occur
										"false"	- No serialisation of data will occur (default).
		
		cache_location				- The location at which any cache file will be created. By default a cache file
									will be created in the temporary directory as defined by any environment variables.
									Failing this it will be created in the current directory.
		
		threshold					- The absolute number of live Objects that can exist at one time before
									serialisation will occur. (1000000)

		cache_pool_size				- The size of a pool containing recently accessed Objects. Any Objects will not be
									serialised whilst they remain in the pool. (100)

		callbacks					- The data associated with this option must be an instance of the SerialisationCallback
									interface which will be used during serialisation. (NULL)
									Note: A given callback interface must remain valid for the lifetime of all Objects created
									during the scope of the callback interface.


	\endverbatim

	<b>Licensing</b>

	The SDK incorporates a standalone license. 

	\verbatim

		CustomerID					- Customers which have been provided with a sold to ID will have to register this ID by 
									  calling initialise and passing their solid to ID as a flattened string in the following
									  format "CustomerID=SoldtoID"; i.e "CustomerID=123456".

	\endverbatim

   <b>Adapter Options</b>

   Provides options for the control of various adapters in the SDK.

   \verbatim

   adapters

      PLMXML
         
         initial_schema_support  - Specifies the level of support for the standard PLM XML schemas that will be 
                                 enabled during Initialise. By default the SDK does not initially provide support
                                 for the following PLM XML extension schema:

                                    PLMXMLBusinessSchema
                                    PLMXMLFDSchema
                                    PLMXMLMechatronicsSchema
                                    PLMXMLRouteListSchema
                                    PLMXMLValidationRuleSchema

                                 Support for these schemas are provided as a separate library that must be 
                                 explicitly loaded into the SDK. Setting this option allows this support to 
                                 automatically be enabled during the Initialisation process.

                                 Note: If this option is enabled it requires that the plmxmlExtensions library is
                                 available and accessible on the 'path' of the current machine.
                                    
                                 The following values are supported:

                                 "standard"  - Support will initially only be provided for a subset of the PLM XML
                                            schemas (default)
         
                                 "enhanced"  - Support will be provided for all standard PLM XML schema.
   \endverbatim

	The function will return an error if there are any problems 
	during initialisation.
        
	@param	nPlugins		Number of plug-in and schema names in pluginNames
	@param	pluginNames	Array of UTF8 encoded names of plug-ins and schemas to be loaded
	@param	nOptions		Number of options specified in 'options'
	@param	options		Array of options that should be applied to the PLM XML session
	@param	pAlloc		Optional pointer to custom memory allocator
	@param	pDealloc		Optional pointer to custom memory deallocator 

	@returns					The error code of the operation:
								ErrorCodeOK - Initialisation succeded.
								ErrorCodeInitRegisterHandlers - Failed to register memory handlers.
								ErrorCodeInitInternalData - Failed to initialise SDK internal data.
								ErrorCodeInitParsers - Failed to initialise built-in XML parsers.
								ErrorCodeInitSchema - Failed to initialise built-in schema definition.
								ErrorCodeInitPlugins - At least one component or schema specified in the 'pluginNames' 
															argument could not be loaded.
*/
PLMXML_API ErrorCode Initialise( 
	int nPlugins = 0, 
	char** pluginNames = NULL,
	int nOptions = 0,
	char** options = NULL,
	AllocatorBase* pAlloc = NULL,
	DeAllocatorBase* pDealloc = NULL );

//////////////////////////////////////////////////////////////////////
//! Terminate the SDK
/*!
    This function should be called by the user at the end of use of the  
    PLM XML SDK.
     
    The function frees internal structures and restores the custom
    memory handlers, if used, back to the default handlers. 
	
    In multi-threading environment, the application is responsible 
    for ensuring that child threads have finished their work before
    calling 'Terminate'.

    In this function all Adapters obtained by the SDK will have 
    the PLMXML_OP_ADAPTER_TERMINATE operation called against them. Each adapter can choose to 
    respond to this operation by performing any adapter specific termination.

    Users should not use any more SDK functionality after calling this
    function, unless they call the 'Initialise' function once again.
    
    Error is returned if any problems occur during the operation.
     
    @returns				The error code of the operation.
							   ErrorCodeOK - Operation succeded.
							   ErrorCodeInitRegisterHandlers - Failed to un-register memory handlers.
							   ErrorCodeInitInternalData - Failed to clear up SDK internal data.
							   ErrorCodeInitParsers - Failed to reset built-in XML parsers.
							   ErrorCodeInitSchema - Failed to reset built-in schema definition.
*/
PLMXML_API ErrorCode Terminate( void );

//////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif // __PLMXML_H__
