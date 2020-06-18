/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "iloader.h"
#include "ierrorhandler.h"

namespace JTSDK
{
	class Loader : public JTSDK::ILoader {
	private :
		IErrorHandler* m_errorHandler;
	public :
		/** Constructor. */
		Loader(IErrorHandler* errorHandler = nullptr) : ILoader(), m_errorHandler(errorHandler){
		}

		/** Destructor. */
		virtual ~Loader(){}

		/** Starts loading the model and feeds the writer with data.
			@param fileName The name of the file that should be loaded.
			@param writer The writer that should be fed with data.
			@return True, if loading succeeded, false otherwise.*/
		bool loadDocument(const std::string& fileName, IConsumer * consumer);

	private:
		/** Disable default copy ctor. */
		Loader(const Loader& pre);

		/** Disable default assignment operator. */
		const Loader& operator= (const Loader& pre) = delete;

	};
}
