/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace JTSDK
{
	class IError;

	/** Interface to handle errors that occur while parsing a JT file*/
	class IErrorHandler
	{
	public:

	public:

		/** Constructor. */
		IErrorHandler();

		/** Destructor. */
		virtual ~IErrorHandler();

		/** If this method returns true, the loader stops parsing immediately. If severity is nor CRITICAL
		and this method returns false, the loader continues loading.*/
		bool virtual handleError(const IError* error) = 0;

	private:

		/** Disable default copy ctor. */
		IErrorHandler(const IErrorHandler& pre) = delete;

		/** Disable default assignment operator. */
		const IErrorHandler& operator= (const IErrorHandler& pre) = delete;

	};
	typedef IErrorHandler* IErrorHandlerPtr;

} 