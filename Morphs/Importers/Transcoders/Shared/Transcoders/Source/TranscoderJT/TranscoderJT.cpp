/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderJT/TranscoderJT.h>
#include "TranscoderException.h"

#include <JTSDK/IConsumer.h>
#include <JTSDK/IErrorHandler.h>
#include <JTSDK/Loader.h>

using namespace Babylon::Transcoder;

#define UNUSED(x) (void)(x)


std::shared_ptr<Asset3D> Babylon::Transcoder::ImportJT(
	const std::string& filename,
	IResourceServer* resourceServer,
	FractionalProgressCallback progress,
	Babylon::Framework::ICancellationTokenPtr cancellationToken,
	const std::unordered_map<std::string, std::string>& options,
	uint64_t* streamSize)
{
	/// avoid unused param warning.
	UNUSED(resourceServer);
	UNUSED(progress);
	UNUSED(cancellationToken);
	UNUSED(options);

	auto istream = resourceServer->RequestTextFileResource(filename);
	if (istream == nullptr)
	{
		throw TranscoderResourceFailedException("resource not found or empty. " + filename);
	}

	size_t s = istream->GetSize();
	char* buffer = (char*)malloc(s);
	if (buffer == nullptr) {
		throw TranscoderResourceFailedException("unable to alloc memory. " + filename);
	}

	if (streamSize != nullptr)
	{
		*streamSize = s;
	}

	try {

		if (istream->ReadFully_s(buffer, s) != s) {
			throw TranscoderResourceFailedException("unable to read. " + filename);
		}

		JTSDK::IConsumer * consumerPtr = nullptr;
		JTSDK::IErrorHandler * errorHandlerPtr = nullptr;
		JTSDK::Loader loader(errorHandlerPtr);

		std::shared_ptr<Asset3D> asset = std::make_shared<Asset3D>();
		return asset;
	}
	catch (const std::exception& e) {
		free(buffer);
		throw e;
	}

}