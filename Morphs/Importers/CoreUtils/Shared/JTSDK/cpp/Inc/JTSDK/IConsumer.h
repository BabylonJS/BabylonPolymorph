/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <JtTk/JtkHierarchy.h>

namespace JTSDK
{

	class IConsumer
	{
	private:

	public:

		IConsumer() {};
		virtual ~IConsumer() {};

		virtual int ConsumeAssembly(JtkAssembly* CurrNode) = 0;
		virtual int ConsumePart(JtkPart* CurrNode) = 0;
		virtual int ConsumeInstance(JtkInstance* CurrNode) = 0;

	private:

		/** Disable default copy ctor. */
		IConsumer(const IConsumer& pre) = delete;

		/** Disable default assignment operator. */
		const IConsumer& operator = (const IConsumer& pre) = delete;

	};

	typedef IConsumer* IConsumerPtr;
}