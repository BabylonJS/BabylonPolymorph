/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>

#include <COLLADAFWIWriter.h>
#include <COLLADAFWUniqueId.h>
#include <COLLADASaxFWLLoader.h>
#include <COLLADASaxFWLIErrorHandler.h>

namespace Babylon
{
    namespace Transcoder
    {
		class Asset3D;
		class Mesh;
		class SceneNode;
		class IResourceServer;

		class Asset3DWriterContext {
		private:
			std::shared_ptr<Asset3D> m_asset3D;
			Framework::ICancellationTokenPtr m_cancellationToken;
			IResourceServer* m_resourceServer = nullptr;

			std::map<COLLADAFW::UniqueId, std::shared_ptr<Mesh>> m_geometryLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<SceneNode>> m_visualSceneLibrary;

			// THIS IS TEMPORARY BINDING TO ALLOW SCENE MOUNT GEOMETRY WITH CONTROLLER WITHOUT THE CONTROLLER LIBRARY SUPPORT - Version 0.1.
			std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId> m_skinLibrary;

		public:
			Asset3DWriterContext(IResourceServer* resourceServer, Framework::ICancellationTokenPtr cancellationToken);
			~Asset3DWriterContext();

			inline std::shared_ptr<Asset3D> getAsset3D() const { return m_asset3D; }
			
			void CheckCancelledAndThrow() {
				if (m_cancellationToken) {
					m_cancellationToken->CheckCancelledAndThrow();
				}
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<Mesh>>& getGeometryLibrary() {
				return m_geometryLibrary;
			}			
			
			std::map<COLLADAFW::UniqueId, std::shared_ptr<SceneNode>>& getVisualSceneLibrary() {
				return m_visualSceneLibrary;
			}

			std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId>& getSkinLibrary() {
				return m_skinLibrary;
			}

			bool hasGeometries() {
				return m_geometryLibrary.size() != 0;
			}			
			
			bool hasVisualScenes() {
				return m_visualSceneLibrary.size() != 0;
			}
		};

		typedef Asset3DWriterContext* Asset3DWriterContextPtr;

		/**
		 * Use this class to handle parsed collada assets 
		 */
        class Asset3DColladaFWWriter : public COLLADAFW::IWriter, COLLADASaxFWL::IErrorHandler {

        private :
			Asset3DWriterContext m_context;

		public :
			Asset3DColladaFWWriter(IResourceServer* resourceServer, Framework::ICancellationTokenPtr cancellationToken);
			~Asset3DColladaFWWriter();

			inline const Asset3DWriterContextPtr getContext() { return &(this->m_context); }
			inline std::shared_ptr<Asset3D> getAsset3D() { return m_context.getAsset3D(); }

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
