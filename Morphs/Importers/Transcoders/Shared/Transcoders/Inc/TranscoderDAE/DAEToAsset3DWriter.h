/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>

#include <COLLADAFWIWriter.h>
#include <COLLADAFWFileInfo.h>
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

		class IDAEMeshBuilder;
		class DAETextureBuilder;
		class DAEMaterialBuilder;
		class DAECameraBuilder;
		class DAELightBuilder;
		class DAENodeBuilder;
		class DAESkeletonBuilder;
		struct DAESkinData;
		struct DAESkinController;
		struct DAEAnimationData;
		struct DAESkin;

		namespace Animation {
			class Skeleton;
		}


		class DAEToAsset3DWriterContext {
		public:
			static const COLLADAFW::FileInfo::UpAxisType defaultUpAxis = COLLADAFW::FileInfo::UpAxisType::Y_UP;

		private:
			std::unordered_map<std::string, std::string> m_options;
			Framework::ICancellationTokenPtr m_cancellationToken;
			IResourceServer* m_resourceServer = nullptr;

			COLLADAFW::FileInfo::UpAxisType m_upAxis ;
			Babylon::Utils::Math::Matrix m_upAxisTransform ;
			float m_scale_meter;
			std::string m_authtool;

			/// animation data
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAEAnimationData>> m_animationData;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAESkinData>> m_skinDataLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAESkinController>> m_skinControllerLibrary;

			/// builders.
			std::map<COLLADAFW::UniqueId, std::shared_ptr<IDAEMeshBuilder>> m_geometryLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAETextureBuilder>> m_imageLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAEMaterialBuilder>> m_effectLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAECameraBuilder>> m_cameraLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAELightBuilder>> m_lightLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAENodeBuilder>> m_nodeLibrary;


			std::map<COLLADAFW::UniqueId, std::shared_ptr<Asset3D>> m_visualSceneLibrary;
			std::map<COLLADAFW::UniqueId, std::shared_ptr<Animation::Skeleton>> m_skeletonLibrary;
			std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId> m_materialUIdToEffectIndex;
			std::map<COLLADAFW::String, COLLADAFW::UniqueId> m_materialOriginalIdToEffectIndex;

			COLLADAFW::UniqueId m_primarySceneId;

		public:
			DAEToAsset3DWriterContext(IResourceServer* resourceServer, const std::unordered_map<std::string, std::string>& options, Framework::ICancellationTokenPtr cancellationToken);
			~DAEToAsset3DWriterContext();

			inline void CheckCancelledAndThrow() {
				if (m_cancellationToken) {
					m_cancellationToken->CheckCancelledAndThrow();
				}
			}

			inline const IResourceServer* getRessourceServer() {
				return m_resourceServer;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAEAnimationData>>& getAnimationData() {
				return m_animationData;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAESkinData>>& getSkinDataLibrary() {
				return m_skinDataLibrary;
			}
			
			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAESkinController>>& getSkinControllerLibrary() {
				return m_skinControllerLibrary;
			}

			std::map<COLLADAFW::UniqueId,std::shared_ptr<Animation::Skeleton>>& getSkeletonLibrary() {
				return m_skeletonLibrary;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<IDAEMeshBuilder>>& getGeometryLibrary() {
				return m_geometryLibrary;
			}			
			
			std::map<COLLADAFW::UniqueId, std::shared_ptr<Asset3D>>& getVisualSceneLibrary() {
				return m_visualSceneLibrary;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAETextureBuilder>>& getImageLibrary() {
				return m_imageLibrary;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAECameraBuilder>>& getCameraLibrary() {
				return m_cameraLibrary;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAELightBuilder>>& getLightLibrary() {
				return m_lightLibrary;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAEMaterialBuilder>>& getEffectLibrary() {
				return m_effectLibrary;
			}

			std::map<COLLADAFW::UniqueId, std::shared_ptr<DAENodeBuilder>>& getNodeLibrary() {
				return m_nodeLibrary;
			}

			std::map<COLLADAFW::UniqueId, COLLADAFW::UniqueId>& getMaterialUIdToEffectIndex() {
				return m_materialUIdToEffectIndex;
			}

			std::map<COLLADAFW::String, COLLADAFW::UniqueId>& getMaterialOriginalIdToEffectIndex() {
				return m_materialOriginalIdToEffectIndex;
			}

			inline bool hasGeometries() {
				return m_geometryLibrary.size() != 0;
			}			
			
			inline bool hasVisualScenes() {
				return m_visualSceneLibrary.size() != 0;
			}


			inline const COLLADAFW::FileInfo::UpAxisType getUpAxisType() {
				return m_upAxis;
			}

			inline const std::string  getBasePath() {
				return m_options[_BASEPATH_OPTION_KEY];
			}

			inline const size_t  getMaxMeshPrimitiveOption() {
				std::string str = m_options[_MAX_MESH_PRIMITIVE_OPTION_KEY];
				if (!str.empty()) {
					uint32_t n = strtoul(str.c_str(), nullptr,  10);
					return errno ? UINT_MAX : n;
				}
				return UINT_MAX;
			}

			inline const Babylon::Utils::Math::Matrix getUpAxisTransfrom() {
				return m_upAxisTransform;
			}


			inline const COLLADAFW::UniqueId getPrimarySceneId() {
				return m_primarySceneId;
			}

			inline const float getScaleMeter() {
				return m_scale_meter;
			}

			inline void setScaleMeter(float scale) {
				m_scale_meter = scale;
			}

			void setUpAxisType(COLLADAFW::FileInfo::UpAxisType t);

			inline void setPrimarySceneId(COLLADAFW::UniqueId uid) {
				m_primarySceneId = uid;
			}

			inline void SetAuthoringTool(std::string authoring_tool) {
				m_authtool = authoring_tool;
			}

			inline const std::string  getAuthoringTool() {
				return m_authtool;
			}

			inline bool hasSkins() { return m_skinControllerLibrary.size() > 0; }

		};

		typedef DAEToAsset3DWriterContext* DAEToAsset3DWriterContextPtr;

		/**
		 * Use this class to handle parsed collada assets 
		 */
        class DAEToAsset3DWriter : public COLLADAFW::IWriter, COLLADASaxFWL::IErrorHandler {

        private :
			DAEToAsset3DWriterContext m_context;

		public :
			DAEToAsset3DWriter(IResourceServer* resourceServer, const std::unordered_map<std::string, std::string>& options, Framework::ICancellationTokenPtr cancellationToken);
			~DAEToAsset3DWriter();

			inline const DAEToAsset3DWriterContextPtr getContext() { return &(this->m_context); }
			
			inline bool hasSkins() { return m_context.hasSkins();  }

			std::shared_ptr<Asset3D> getAsset3D();

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
