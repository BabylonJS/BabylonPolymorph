//////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_ALLOCATOR_HPP__
#define __PLMXML_ALLOCATOR_HPP__

#ifndef __PLMXML_H__
#include <plmxml.h>
#endif

#ifndef _AIX

/*
	Global overrides for new and delete operators. To use
	simply include the header file in a source file in the 
	projec
*/

#if !defined(PLMXML_DEFAULT_ALLOCATORS) && !defined(PLMXML_STATIC_LIBS)

#if defined __hpux
#ifdef __bad_alloc
#define PLMXML_THROW_NEW       throw(__bad_alloc)
#else
#define PLMXML_THROW_NEW		throw()
#endif
#define PLMXML_THROW_DELETE    throw()
#elif defined __linux__ || __APPLE__  || ( defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x5120 && __SUNPRO_CC < 0x5140)
#include <new>
#define PLMXML_THROW_NEW       throw(std::bad_alloc)
#define PLMXML_THROW_DELETE    throw()
#elif defined __SUNPRO_CC && __SUNPRO_CC >= 0x5140
#define PLMXML_THROW_NEW
#define PLMXML_THROW_DELETE    throw()
#else
#define PLMXML_THROW_NEW
#define PLMXML_THROW_DELETE
#endif

void* operator new( size_t size ) PLMXML_THROW_NEW
{	
	return plmxml_api::Allocator::allocate( size );
}

void* operator new[]( size_t size ) PLMXML_THROW_NEW
{
	return plmxml_api::Allocator::allocate( size );
}

void operator delete( void* p ) PLMXML_THROW_DELETE
{
	plmxml_api::Allocator::deallocate( p );
}

void operator delete[]( void* p ) PLMXML_THROW_DELETE
{
	plmxml_api::Allocator::deallocate( p );
}

#endif

#endif

#endif // !__PLMXML_ALLOCATOR_HPP__
