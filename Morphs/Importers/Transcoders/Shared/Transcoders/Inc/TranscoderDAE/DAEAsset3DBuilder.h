/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEToAsset3DWriter.h>

namespace Babylon
{
	namespace Transcoder
	{
		template<typename T>
		class DAEAsset3DBuilder {

		protected:
			DAEToAsset3DWriterContextPtr m_context;
			std::string m_name;

		public:
			DAEAsset3DBuilder(DAEToAsset3DWriterContextPtr context) :
				m_context(context)
			{
			}

			~DAEAsset3DBuilder() {
			}

			inline DAEToAsset3DWriterContextPtr GetContext() { return m_context; }
			inline std::string GetName() { return m_name; }

			inline DAEAsset3DBuilder& WithName(std::string name) {
				m_name = std::move(name);
				return *this;
			}

			virtual std::shared_ptr<T> Build() = 0 ;
		};
	}
}
