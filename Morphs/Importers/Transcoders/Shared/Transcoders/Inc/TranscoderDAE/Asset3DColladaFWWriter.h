/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>
#include <COLLADAFWIWriter.h>
#include <COLLADASaxFWLLoader.h>
#include <COLLADASaxFWLIErrorHandler.h>

namespace Babylon
{
    namespace Transcoder
    {
        class Asset3D;
		
		/**
		 * Use this class to handle parsed collada assets 
		 */
        class Asset3DColladaFWWriter : public COLLADAFW::IWriter, COLLADASaxFWL::IErrorHandler {

        private :
			std::shared_ptr<Asset3D> m_asset3D;

		public :
			Asset3DColladaFWWriter();
			~Asset3DColladaFWWriter();

			inline std::shared_ptr<Asset3D> GetAsset3D() const { return m_asset3D; }

 			/** If this method returns true, the loader stops parsing immediately. If severity is nor CRITICAL
			and this method returns false, the loader continues loading.*/
			bool virtual handleError(const COLLADASaxFWL::IError* error);

			/** This method will be called if an error in the loading process occurred and the loader cannot
			continue to to load. The writer should undo all operations that have been performed.
			@param errorMessage A message containing informations about the error that occurred.
			*/
			void cancel(const COLLADAFW::String& errorMessage) ;

			/** This is the method called. The writer hast to prepare to receive data.*/
			void start();

			/** This method is called after the last write* method. No other methods will be called after this.*/
			void finish();

			/** When this method is called, the writer must write the global document asset.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeGlobalAsset(const COLLADAFW::FileInfo* asset);

			/** When this method is called, the writer must write the scene.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeScene(const COLLADAFW::Scene* scene);

			/** When this method is called, the writer must write the entire visual scene.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeVisualScene(const COLLADAFW::VisualScene* visualScene);

			/** When this method is called, the writer must handle all nodes contained in the
			library nodes.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeLibraryNodes(const COLLADAFW::LibraryNodes* libraryNodes);

			/** When this method is called, the writer must write the geometry.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeGeometry(const COLLADAFW::Geometry* geometry);

			/** When this method is called, the writer must write the material.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeMaterial(const COLLADAFW::Material* material);

			/** When this method is called, the writer must write the effect.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeEffect(const COLLADAFW::Effect* effect);

			/** When this method is called, the writer must write the camera.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeCamera(const COLLADAFW::Camera* camera);

			/** When this method is called, the writer must write the image.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeImage(const COLLADAFW::Image* image);

			/** When this method is called, the writer must write the light.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeLight(const COLLADAFW::Light* light);

			/** When this method is called, the writer must write the Animation.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeAnimation(const COLLADAFW::Animation* animation);

			/** When this method is called, the writer must write the AnimationList.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeAnimationList(const COLLADAFW::AnimationList* animationList);

			/** When this method is called, the writer must write the AnimationClip.
			@return The writer should return true, of writing succeeded, false otherwise.*/
			bool writeAnimationClip(const COLLADAFW::AnimationClip* animationClip);

			/** When this method is called, the writer must write the skin controller data.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeSkinControllerData(const COLLADAFW::SkinControllerData* skinControllerData);

			/** When this method is called, the writer must write the controller.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeController(const COLLADAFW::Controller* controller);

			/** When this method is called, the writer must write the formulas. All the formulas of the entire
			COLLADA file are contained in @a formulas.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeFormulas(const COLLADAFW::Formulas* formulas);

			/** When this method is called, the writer must write the kinematics scene.
			@return The writer should return true, if writing succeeded, false otherwise.*/
			bool writeKinematicsScene(const COLLADAFW::KinematicsScene* kinematicsScene);
        };

    }
}
