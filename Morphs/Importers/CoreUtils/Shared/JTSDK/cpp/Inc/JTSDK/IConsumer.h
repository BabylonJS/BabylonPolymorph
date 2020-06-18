/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace JTSDK
{

	class IConsumer
	{
	private:

	public:

		IConsumer() {};
		virtual ~IConsumer() {};


	private:

		/** Disable default copy ctor. */
		IConsumer(const IConsumer& pre) = delete;

		/** Disable default assignment operator. */
		const IConsumer& operator = (const IConsumer& pre) = delete;

	};
}