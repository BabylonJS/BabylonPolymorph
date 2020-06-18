/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace JTSDK
{
	class IError;

	/** Error class */
	class IError
	{
	public:

	public:

		/** Constructor. */
		IError();

		/** Destructor. */
		virtual ~IError();


	private:

		/** Disable default copy ctor. */
		IError(const IError& pre) = delete;

		/** Disable default assignment operator. */
		const IError& operator= (const IError& pre) = delete;

	};
	typedef IError* IErrorPtr;

}