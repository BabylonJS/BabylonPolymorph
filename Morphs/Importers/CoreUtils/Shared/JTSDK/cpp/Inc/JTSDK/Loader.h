/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "iloader.h"
#include "IErrorHandler.h"
#include "IConsumer.h"
#include <JtTk/JtkClientData.h>
#include <JtTk/JtkHierarchy.h>

namespace JTSDK
{

	/** 
	 the context which is is passed to traverseGraph method.
	 this is the only way we have to keep ref to the consumer.
	 */
	class LoaderContext : public JtkClientData {

	private:
		IConsumerPtr m_consumer;
	public:
		IConsumerPtr GetConsumer() {
			return m_consumer;
		}

	protected:
		LoaderContext(IConsumerPtr consumer) : JtkClientData(), m_consumer(consumer) {
		}

		~LoaderContext(){}


		friend class Loader;
	};

	class Loader : public JTSDK::ILoader {
	public:
		static LoaderContext * createContext(IConsumerPtr consumer) {
			return new LoaderContext(consumer);
		}

	private :
		IErrorHandlerPtr m_errorHandler;
	public :

		/** Constructor. */
		Loader(IErrorHandlerPtr errorHandler = nullptr) : ILoader(), m_errorHandler(errorHandler){
		}

		/** Destructor. */
		virtual ~Loader(){}

		/** Starts loading the model and feeds the writer with data.
			@param fileName The name of the file that should be loaded.
			@param writer The writer that should be fed with data.
			@return True, if loading succeeded, false otherwise.*/
		bool loadDocument(unsigned char* Buffer, const int BuffLen, IConsumerPtr consumer);

	private:
		/** Disable default copy ctor. */
		Loader(const Loader& pre);

		/** Disable default assignment operator. */
		const Loader& operator= (const Loader& pre) = delete;

	};
}
