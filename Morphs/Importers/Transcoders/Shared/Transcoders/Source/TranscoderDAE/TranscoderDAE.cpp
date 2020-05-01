/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAE.h>
#include <TranscoderDAE/Asset3DColladaFWWriter.h>
#include "TranscoderException.h"


#include <COLLADASaxFWLLoader.h>
#include <COLLADAFWRoot.h>

using namespace Babylon::Transcoder;

#define UNUSED(x) (void)(x)

static bool ShouldBeLoaded(const COLLADABU::URI&, COLLADAFW::FileId) {
	return false;
}



std::shared_ptr<Asset3D> Babylon::Transcoder::ImportDAE(
	const std::string& filename, 
	IResourceServer* resourceServer, 
	FractionalProgressCallback progress,
	Babylon::Framework::ICancellationTokenPtr cancellationToken,
	const std::unordered_map<std::string, std::string>& options,
	uint64_t* streamSize)
{
	/// avoid unused param warning.
	UNUSED(progress);
	UNUSED(options);

	auto istream = resourceServer->RequestTextFileResource(filename);
	if (istream == nullptr)
	{
		throw TranscoderResourceFailedException("resource not found or empty. " + filename);
	}

	size_t s = istream->GetSize();
	char* buffer = (char*)malloc(s);
	if(buffer == nullptr) {
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

		Asset3DColladaFWWriter writer(resourceServer,cancellationToken) ;
		COLLADASaxFWL::IErrorHandler* errorHandler = (COLLADASaxFWL::IErrorHandler*) &writer;
		COLLADASaxFWL::Loader* loader = new COLLADASaxFWL::Loader(errorHandler);
		loader->registerExternalReferenceDeciderCallbackFunction(ShouldBeLoaded);

		COLLADAFW::Root root(loader, &writer);
		
		if (!root.loadDocument(filename,buffer,s)) {
			throw TranscoderResourceFailedException("unable to load document. " + filename);
		}

		free(buffer);

		std::shared_ptr<Asset3D> asset = writer.getAsset3D();
	
		Asset3DWriterContextPtr ctx = writer.getContext();
		if (ctx) {
			/** 
			 * some Collada file does NOT define visual scenes, then do NOT instantiate models.
			 * this appear to be a default behaviors of some transcoder. In this case, only save the model as
			 * direct child node of the Asset3D, without any transformation.
			 */
			if (!ctx->hasVisualScenes()) {
				/// bind geometries to the asset.
				if (ctx->hasGeometries()) {
					std::map<std::string, std::shared_ptr<Mesh>>& lib = ctx->getGeometryLibrary();
					std::map<std::string, std::shared_ptr<Mesh>>::iterator it = lib.begin();
					while (it != lib.end())
					{
						std::shared_ptr<Mesh> m = it->second;
						std::shared_ptr<SceneNode> n = asset->CreateChildNode();
						if (n) {
							n->SetMesh(m);
						}
						it++;
					}
				}
			}
		}
		return asset;
	}
	catch (const std::exception& e) {
		free(buffer);
		throw e;
	}

}