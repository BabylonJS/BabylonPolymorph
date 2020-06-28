/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"
#include <JtTk/JtkEntityFactory.h>
#include <TranscoderJT/TranscoderJTutils.h>

std::string Babylon::Transcoder::JtkString2String(JtkString src) {
	char* c;
	int l ;
	src.getString(c, l);
	std::string result(c);
	JtkEntityFactory::deleteMemory(c);
	return result;
}


Babylon::Utils::Math::Matrix  Babylon::Transcoder::toBabylonMatrix(JtkTransform * jtkMatrix) {

	/**
	 * The Babylon math library packs matrices in a row major order.
	 * data - A sixteen element double precision array specifying a 4x4 transformation matrix in row-major format. 
	 */
	float* data;
	if (jtkMatrix->getTElements(data)) {
		Babylon::Utils::Math::Matrix m(data);
		/* The JtTk allocates memory for the valarray array */
		JtkEntityFactory::deleteMemory(data);
		return m;
	}  
	return Babylon::Utils::Math::Matrix::Identity;
}