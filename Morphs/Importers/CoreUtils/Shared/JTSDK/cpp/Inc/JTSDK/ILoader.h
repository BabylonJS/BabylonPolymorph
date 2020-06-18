/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include<string>

namespace JTSDK
{
	class IConsumer;

	class ILoader
	{
	private:

	public:

		ILoader() {};
		virtual ~ILoader() {};

		/** Starts loading the model and feeds the writer with data.
		@param fileName The name of the file that should be loaded.
		@param writer The writer that should be fed with data.
		@return True, if loading succeeded, false otherwise.*/
		virtual bool loadDocument(const std::string& fileName, IConsumer* writer) = 0;

	private:

		/** Disable default copy ctor. */
		ILoader(const ILoader& pre);

		/** Disable default assignment operator. */
		const ILoader& operator = (const ILoader& pre) = delete;

	};
}