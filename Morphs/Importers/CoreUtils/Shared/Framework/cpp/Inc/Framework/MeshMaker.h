/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Enums.h>
#include <Framework/Types.h>
#include <Framework/MemoryBuffer.h>
#include <Framework/GeometryWriter.h>
#include <Framework/GeometryUtils.h>
#include <Framework/MaterialWriter.h>
#include <Framework/TextureWriter.h>
#include <Framework/MetadataWriter.h>
#include <Framework/Vertex.h>
#include <Framework/Plugin.h>

#include <CoreUtils/SpectreSDK.h>
#include <CoreUtils/Hash.h>
#include <CoreUtils/Cancellation.h>
#include <CoreUtils/Tracked.h>

#include <cstdint>
#include <cstring>
#include <map>
#include <atomic>
#include <fstream>
#include <functional>
#include <queue>

//  Disable metadata frames.
//  Metadata frames are prone to ID collisions - SceneNode / Material / Texture may have the same IDs
//  Also metadata frames are currently never used.
#define FEATURE_ENABLE_METADATA_FRAMES 0

namespace Spectre
{
    namespace Framework
    {
        class MeshMaker;
        class MaterialMaker;
        class TextureMaker;
        class LightMaker;
        class AnimationMaker;
        class SkeletonMaker;

        typedef std::function<void SPECTRESDK_CALL (MeshMaker* pMesh)> ProcessMeshCallback;
        typedef std::function<void SPECTRESDK_CALL (MaterialMaker* pMesh)> ProcessMaterialCallback;
        typedef std::function<void SPECTRESDK_CALL (TextureMaker* pMesh)> ProcessTextureCallback;
        typedef std::function<void SPECTRESDK_CALL (LightMaker*)> ProcessLightCallback;
        typedef std::function<void SPECTRESDK_CALL (Frame*, std::string const& metadataJSON)> OnFrameCallback;
        typedef std::function<void SPECTRESDK_CALL (AnimationMaker* pAnim)> ProcessAnimationCallback;
        typedef std::function<void SPECTRESDK_CALL (SkeletonMaker* pAnim)> ProcessSkeletonCallback;

        /*
        * Class used to manage the creation of data in the common object (Beihai Exchange) format
        */
        class DataMaker : Utils::InstanceCounter<DataMaker>
        {
        public:
            DataMaker(
                EncodeBGRAFunc encodeFunc,
                int textureCompression,
                EByteOrder outputByteOrder = kLittleEndian,
                ConverterLODMode textureLODMode = ConverterLODMode::kNoLOD);

            DataMaker(
                EncodeBGRAFunc encodeFunc,
                EncodeRAWBGRAFunc rawEncodeFunc,
                int textureCompression,
                EByteOrder outputByteOrder = kLittleEndian,
                ConverterLODMode textureLODMode = ConverterLODMode::kNoLOD);

            ~DataMaker();

            /*
            * Create a geometric mesh using names. The specified callback will be invoked later on as the mesh
            * is being serialized
            */
            std::shared_ptr<MeshMaker> CreateMesh(
                const char* name,
                const char* parentName,
                const char* materialName,
                uint32_t numVertices,
                uint32_t numIndices,
                uint32_t vertexFormatMask,
                GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
                ProcessMeshCallback createMeshCB);

            /*
            * Create a geometric mesh using ids. The specified callback will be invoked later on as the mesh
            * is being serialized
            */
            std::shared_ptr<MeshMaker> CreateMesh(
                const char* name,
                uint32_t id,
                uint32_t parentId,
                uint32_t materialId,
                uint32_t numVertices,
                uint32_t numIndices,
                bool areIndices32bit,
                uint32_t vertexFormatMask,
                GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
                ProcessMeshCallback createMeshCB);

            /*
            * Create an empty node using name, which contains only a name and a transform
            */
            std::shared_ptr<MeshMaker> CreateEmptyNode(
                const char* name,
                const char* parentName,
                ProcessMeshCallback createNodeCB);

            /*
            * Create an empty node using id, which contains only a name and a transform
            */
            std::shared_ptr<MeshMaker> CreateEmptyNode(
                const char* name,
                uint32_t id,
                uint32_t parentId,
                ProcessMeshCallback createNodeCB);

            /*
            * Create a material using name
            */
            std::shared_ptr<MaterialMaker> CreateMaterial(
                const char* name,
                ProcessMaterialCallback createMaterialCB);

            /*
            * Create a material using id
            */
            std::shared_ptr<MaterialMaker>  CreateMaterial(
                const char* name,
                uint32_t id,
                ProcessMaterialCallback createMaterialCB);

            /*
            * Create a texture from stream using name
            */
            std::shared_ptr<TextureMaker>  CreateTexture(
                const char* name,
                std::string const& path,
                std::ifstream&& inputStream,
                ProcessTextureCallback createTextureCB,
                TextureMaterialLayer layer = TextureMaterialLayer::kDiffuse,
                float scaleFactor = 1.0f);

            /*
            * Create a texture from buffer using name
            */
            std::shared_ptr<TextureMaker> CreateTexture(
                const char* name,
                std::string const& path,
                std::unique_ptr<uint8_t[]>&& data,
                uint32_t dataSizeInBytes,
                ProcessTextureCallback createTextureCB,
                TextureMaterialLayer layer = TextureMaterialLayer::kDiffuse,
                float scaleFactor = 1.0f);

            /*
            * Create a texture from buffer using id
            */
            std::shared_ptr<TextureMaker> CreateTexture(
                const char* name,
                uint32_t id,
                std::unique_ptr<uint8_t[]>&& data,
                uint32_t    width,
                uint32_t    height,
                uint32_t    lineStride,
                uint32_t    size,
                Framework::TextureSegment::EFormat format,
                uint8_t flags,
                TextureMaterialLayer layer = TextureMaterialLayer::kDiffuse,
                float scaleFactor = 1.0f);

            /*
            * Create a light with the specified name, parent and creation callback using name
            */
            std::shared_ptr<LightMaker> CreateLight(
                const char* name,
                const char* parentName,
                ProcessLightCallback createLightCB);

            /*
            * Create a light with the specified name, parent and creation callback using id
            */
            std::shared_ptr<LightMaker>  CreateLight(
                const char* name,
                uint32_t id,
                uint32_t parentid,
                ProcessLightCallback createLightCB);

            /*
            * Create a skeleton
            */
            std::shared_ptr<SkeletonMaker> CreateSkeleton(
                const char* skeletonName,
                const char* parentNodeName,
                ProcessSkeletonCallback createSkeletonCB);

            /*
            * Create an animation with the specified name.
            */
            std::shared_ptr<AnimationMaker> CreateAnimation(
                const std::string& animationName,
                ProcessAnimationCallback createAnimCB);

            /*
            * Create a texture whose data is delayed - ie. will arrive later on. Return the Id of the texture
            */
            uint32_t CreateTextureDelayed(
                const char* name,
                std::string const& path,
                ProcessTextureCallback createTextureCB);

            /*
            * Call this to provide the data for a delayed texture. The texture will not be processed until
            * the delayed texture's data has arrived
            */
            void UpdateDelayedTexture(
                uint32_t textureId,
                std::unique_ptr<uint8_t[]>&& data,
                uint32_t dataSizeInBytes,
                OnFrameCallback callback);

            /*
            * Call to remove Texture from delayed queued; for example the resource cannot be found
            */
            void RemoveTexture(uint32_t id, OnFrameCallback callback);

            /*
            * Find the skeleton for the specified node
            */
            std::shared_ptr<SkeletonMaker> FindSkeletonForNode(void* node) const;

            /*
            * Call this to provide the scene options: currently scale factor and system unit.
            */
            void SetSceneOptions(float scaleFactor, float systemUnitInCentimetres);

            /*
            * Call this to provide the root bounding box for all root level scene nodes.
            * This must be calculated externally and allows you to merge the bounding boxes
            * of separated meshes. A single root node will be created to connect to the root
            * level nodes, this model root node will be scaled to fit the model into a unit viewing
            * volume. If this is not set then any bounds already set on the nodes will be used instead.
            */
            void SetRootBounds(DirectX::BoundingBox rootBounds);

            /*
            * Call this method once all the meshes, textures, materials, anims etc.. have been created.
            * This kicks off the conversion process. The method will invoke the user supplied *callback*
            * each time a new frame is generated.
            * The data will be optimally laid out. A cancellation token must be passed in, to allow
            * cancelling long-running async operations (delayed textures).
            */
            void Emit(
                OnFrameCallback callback,
                Spectre::Framework::ICancellationTokenPtr cancellationToken);

            void RegisterName(const std::string& name, uint32_t id);

        protected:
            typedef std::vector<std::shared_ptr<class MeshMaker>> MeshContainer;
            typedef MeshContainer::iterator MeshIterator;

            typedef std::map<uint32_t, std::shared_ptr<class MaterialMaker>> MaterialContainer;
            typedef MaterialContainer::iterator MaterialIterator;

            typedef std::map<uint32_t, std::shared_ptr<class LightMaker>> LightContainer;
            typedef LightContainer::iterator LightIterator;

            typedef std::map<uint32_t, std::shared_ptr<class TextureMaker>> TextureContainer;
            typedef TextureContainer::iterator TextureIterator;

#if FEATURE_ENABLE_METADATA_FRAMES
            typedef std::map<uint32_t, std::string> NameMappingContainer;
            typedef NameMappingContainer::iterator NameMappingIterator;
#endif

            typedef std::map<uint32_t, std::shared_ptr<class AnimationMaker>> AnimationContainer;
            typedef AnimationContainer::iterator AnimationIterator;

            typedef std::map<uint32_t, std::shared_ptr<class SkeletonMaker>> SkeletonContainer;
            typedef SkeletonContainer::iterator SkeletonIterator;

            typedef std::vector<ITextureWriter*> TextureWriters;
            typedef TextureWriters::iterator TextureWritersIterator;
            typedef TextureWriters::reverse_iterator TextureWritersRevIterator;

            // Contains the list of meshes
            MeshContainer        m_meshes;
            MaterialContainer    m_materials;
            LightContainer       m_lights;
            TextureContainer     m_textures;
            AnimationContainer   m_animations;
            SkeletonContainer    m_skeletons;

#if FEATURE_ENABLE_METADATA_FRAMES
            NameMappingContainer m_nameMap;
#endif

            SceneDefinition      m_scene;

            EByteOrder           m_byteOrder;
            int                  m_textureCompression;
            ConverterLODMode     m_textureLODMode;
            std::mutex m_lock;

            EncodeBGRAFunc m_encodeFunc;
            EncodeRAWBGRAFunc m_rawEncodeFunc;

            // Bounding box to represent the merged bounding box of all
            // nodes attached to the root. If this is not set then we will
            // take the bounds already set on the given nodes.
            DirectX::BoundingBox m_rootBounds = DirectX::BoundingBox(Vector3::Zero, Vector3::Zero);

        private:
            ImageReader PathToImageReader(std::string const& path);
            void TryProcessTextureLODs(OnFrameCallback callback);
            void ProcessTextures(OnFrameCallback callback);

            void PreprocessMeshes();

            void CreateTextureLODWriters(TextureWriters& writers);
        };

        /*
        * Class used to create meshes. It leverages a geometry writer to handle memory
        * and serialization. This way, we avoid extra copies by using the final format
        * as an intermediate format.
        * The MeshMaker will create its own geometryWriter if needed. Alternatively, one can be
        * specified, which will allow meshes to be aggregated to the same writer
        */
        class MeshMaker : Spectre::Utils::InstanceCounter<MeshMaker>
        {
            friend class DataMaker;
        public:
            // Geometric Data for the Mesh
            inline const float* GetPositions() const;
            inline const uint32_t* GetIndices() const;
            inline float* GetNormals();

            inline uint32_t GetVertexCount() const;
            inline uint32_t GetIndexCount() const;

            inline void SetPosition(uint32_t vertexIndex, float x, float y, float z);
            inline void SetPositions(Utils::Math::Vector3 const* positions, uint32_t numPositions);
            inline void SetNormal(uint32_t vertexIndex, float x, float y, float z);
            inline void SetNormals(Utils::Math::Vector3 const* normals, uint32_t numNormals);
            inline void SetTangent(uint32_t vertexIndex, float x, float y, float z, float w);
            inline void SetColor(uint32_t vertexIndex, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
            inline void SetUV0(uint32_t vertexIndex, float u, float v);
            inline void SetUV1(uint32_t vertexIndex, float u, float v);
            inline void SetIndices(uint32_t const* indices, uint32_t numIndices);
            inline void SetBlendInfo(uint32_t vertexIndex, int blendIndex, uint16_t jointIndex, float jointWeight);

            inline void SetLocalToParentTransform(const float* pMatrix44);
            inline void SetLocalToParentTransform(const double* pMatrix44);

            inline const float* GetLocalToParentTransform();

            inline void SetBoundingBox(const float* pBoundingBox);
            inline void SetDisabled();
            inline void SetFlags(uint16_t flag);

            inline const float* GetBoundingBox();

            inline uint32_t GetID() const { return m_id; }
            inline uint32_t GetParentID() const { return m_parentId; }
            inline uint32_t GetMaterialID() const { return m_materialId; }
            inline uint32_t GetSkeletonID() const { return m_skeletonId; }
            inline uint32_t GetNumIndices() const { return m_numIndices; }
            inline uint32_t GetNumVertices() const { return m_numVertices; }
            inline GeometryUtils::TriangleMeshAnalysisResults const& GetMeshAnalysisResults() const { return m_meshAnalysisResults; }

            void SetMaterialId(uint32_t materialId) { m_materialId= materialId; }
            void SetParentId(uint32_t parentId) { m_parentId = parentId; }
            void SetSkeletonId(uint32_t skeletonId) { m_skeletonId= skeletonId; }
            void SetNumVertices(uint32_t numVertices) { m_numVertices = numVertices; }
            void SetNumIndices(uint32_t numIndices) { m_numIndices= numIndices; }
            void SetFormatMask(uint32_t formatMask) { m_formatMask = formatMask; }
            void SetMeshAnalysisResults(GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults) {   m_meshAnalysisResults = meshAnalysisResults; }
            void AddProcessMeshCallback(ProcessMeshCallback callback)   {   m_callbacks.push_back(callback);    }

            MeshMaker(
                const char* name,
                const char* parentName,
                const char* materialName,
                uint32_t numVertices,
                uint32_t numIndices,
                uint32_t formatMask,
                Framework::GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
                ProcessMeshCallback callback);

            MeshMaker(
                const char* name,
                uint32_t id,
                uint32_t parentId,
                uint32_t materialId,
                uint32_t numVertices,
                uint32_t numIndices,
                bool areIndices32bit,
                uint32_t formatMask,
                Framework::GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
                ProcessMeshCallback callback);

            MeshMaker(
                const char* name,
                const char* parentName,
                ProcessMeshCallback callback);

            MeshMaker(
                const char* name,
                uint32_t id,
                uint32_t parentId,
                ProcessMeshCallback callback);

            ~MeshMaker();

            void AllocateMeshBuffers(uint32_t vertexCount, uint32_t indexCount);

        protected:
            void CreateMesh(IGeometryWriter* writer, DirectX::BoundingBox rootBounds);
            void FitMeshToViewingVolume(DirectX::BoundingBox bounds);

        protected:
            IGeometryWriter* m_writer = nullptr;
            VertexData m_lockedVertexData;

            std::string m_name;
            std::string m_parentName;
            std::string m_materialName;

            uint32_t m_id = 0;
            uint32_t m_parentId = 0;
            uint32_t m_materialId = 0;
            uint32_t m_skeletonId = 0;
            uint32_t m_numVertices = 0;
            uint32_t m_numIndices = 0;
            uint32_t m_formatMask = 0;
            uint16_t m_flags = 0;
            bool m_areIndices32bit = true;
            GeometryUtils::TriangleMeshAnalysisResults m_meshAnalysisResults;

            float m_boundingBox[6] = { 0 };
            bool m_hasBoundingBox = false;
            std::vector<ProcessMeshCallback> m_callbacks;
        };


        /*
        * Class used to create materials ready for serialization into the common object format
        */
        class MaterialMaker : Spectre::Utils::InstanceCounter<MaterialMaker>
        {
            friend class DataMaker;
        public:
            using Layer = MaterialLayer;

            inline void SetHairShader() { m_setHairShader = true; }

            inline void SetSpectreRenderingMode(Framework::MaterialDefinition::SpectreRenderingMode mode) { m_spectreRenderingMode = mode; }
            inline void SetSpectreRenderingOptions(Framework::MaterialDefinition::SpectreRenderingOptions options) { m_spectreRenderingOptions = options; }
            inline void AppendSpectreRenderingOption(Framework::MaterialDefinition::SpectreRenderingOption option) { m_spectreRenderingOptions |= option; }
            inline Framework::MaterialDefinition::SpectreRenderingMode GetSpectreRenderingMode() const { return m_spectreRenderingMode; }

            inline void SetLayerColor(Layer layer, uint32_t rgba);
            inline void SetLayerMap(Layer layer, const char* name);
            inline void SetLayerMap(Layer layer, uint32_t textureId);

            inline void SetLayerMapFilter(Layer layer, SamplerDefinition::EFilterMode filter);
            inline void SetLayerMapAddress(Layer layer,
                                           SamplerDefinition::EAddressMode addressU,
                                           SamplerDefinition::EAddressMode addressV);
            inline void SetLayerMapAddress(Layer layer,
                                           SamplerDefinition::EAddressMode addressU,
                                           SamplerDefinition::EAddressMode addressV,
                                           SamplerDefinition::EAddressMode addressW);
            inline void SetLayerMapOffset(Layer layer, float uOffset, float vOffset);
            inline void SetLayerMapTiling(Layer layer, float uTiling, float vTiling);

            MaterialMaker(const char* materialName, ProcessMaterialCallback callback);
            MaterialMaker(const char* name, uint32_t materialId, ProcessMaterialCallback callback);
            ~MaterialMaker();

        protected:
            void CreateMaterial(IMaterialWriter* writer);
            void InitAllLayers();

            inline uint32_t GetID() const { return m_id; }

            struct LayerInfo
            {
                bool m_hasColor = false;
                uint32_t m_color = 0;
                std::string m_mapName;
                SamplerDefinition m_sampler;
                uint32_t m_id = 0;

                uint32_t GetID() const;
            };

        protected:
            std::string m_name;
            uint32_t m_id = 0;

            ProcessMaterialCallback m_callback;
            LayerInfo m_layers[(int)Layer::kNumLayers];
            bool m_setHairShader = false;
            bool m_hashNames = true;

            Framework::MaterialDefinition::SpectreRenderingMode m_spectreRenderingMode = Framework::MaterialDefinition::SpectreRenderingMode::Default;
            Framework::MaterialDefinition::SpectreRenderingOptions m_spectreRenderingOptions = 0;
        };

        /*
        * Class used to create textures ready for serialization into the common object format
        */
        class TextureMaker : Spectre::Utils::InstanceCounter<TextureMaker>
        {
            friend class DataMaker;
        public:
            // :TODO: Controls to allow client to control output format, mips, etc...

            TextureMaker(
                const std::string& name,
                const std::string& path,
                ImageReader reader,
                std::ifstream&& inputStream,
                ProcessTextureCallback callback,
                int textureCompression);

            TextureMaker(
                const std::string& name,
                const std::string& path,
                ImageReader reader,
                ProcessTextureCallback callback,
                int textureCompression);

            TextureMaker(
                const std::string&              name,
                const std::string&              path,
                ImageReader                     reader,
                std::unique_ptr<uint8_t[]>&&    pData,
                uint32_t                        sizeInBytes,
                int                             textureCompression,
                int                             reserved);

            TextureMaker(
                const std::string&              name,
                uint32_t                        id,
                std::unique_ptr<uint8_t[]>&&    data,
                uint32_t                        width,
                uint32_t                        height,
                uint32_t                        stride,
                uint32_t                        size,
                Framework::TextureSegment::EFormat format,
                uint8_t                         flags);

            ~TextureMaker();

            void SetLODProcessingAlgorithm(TextureLOD algo) { m_lodProcessing = algo; }

        protected:
            void CreateTexture(ITextureWriter* writer, uint32_t lod);
            void CreateTextureLOD(std::vector<ITextureWriter*>& writers, EncodeBGRAFunc encodeFunc);
            void CreateRAWTextureLOD(std::vector<class ITextureWriter*>& writers, EncodeRAWBGRAFunc rawEncodeFunc);
            void CreateTextureEncoded(ITextureWriter* writer);
            void SetDelayedData(std::unique_ptr<uint8_t[]>&& pData, uint32_t sizeInBytes);

            inline uint32_t GetID() const { return m_id; }
            inline TextureLOD GetLODProcessingAlgorithm() const { return m_lodProcessing; }
            inline bool IsDelayedTexture() const { return m_isDelayedTexture; }
            inline bool IsWaitingForData() const { return m_waitingForData; }
            inline void SetTextureCompression(int textureCompression) { m_textureCompression = textureCompression; }
            inline void SetTextureLayer(TextureMaterialLayer layer) { m_textureLayer = layer; }
            inline void SetScaleFactor(float factor) { m_scaleFactor = factor; }

        protected:
            std::string     m_name;
            std::string     m_path;
            uint32_t        m_id = 0;
            TextureLOD      m_lodProcessing;

            std::ifstream               m_inputStream;
            std::unique_ptr<uint8_t[]>  m_delayedData;
            uint32_t                    m_delayedDataSizeInBytes = 0;
            uint32_t                    m_height = 0;
            uint32_t                    m_width = 0;
            uint32_t                    m_lineStride = 0;
            Framework::TextureSegment::EFormat m_format;
            uint8_t                     m_flags = 0;

            std::atomic<bool>       m_waitingForData;
            bool                    m_isDelayedTexture = false;

            ProcessTextureCallback  m_callback;
            ITextureWriter*         m_writer = nullptr;

            ImageReader     m_reader;
            int             m_textureCompression = 0;
            TextureMaterialLayer m_textureLayer;
            float           m_scaleFactor;
        };

        //---------------------------------------------------------------------
        // M A T E R I A L   M A K E R   I N L I N E S
        //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerColor(Layer layer, uint32_t abgr)
        {
            m_layers[static_cast<int>(layer)].m_color = abgr;
            m_layers[static_cast<int>(layer)].m_hasColor = true;
        }

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerMap(Layer layer, const char* name)
        {
            m_layers[static_cast<int>(layer)].m_mapName = name;
        }

        //---------------------------------------------------------------------

        inline void MaterialMaker::SetLayerMap(Layer layer, uint32_t textureId)
        {
            m_layers[static_cast<int>(layer)].m_mapName = "";
            m_layers[static_cast<int>(layer)].m_id = textureId;
        }

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerMapFilter(Layer layer, SamplerDefinition::EFilterMode filter)
        {
            m_layers[static_cast<int>(layer)].m_sampler.FilterMode = filter;
        }

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerMapAddress(
            Layer layer,
            SamplerDefinition::EAddressMode addressU,
            SamplerDefinition::EAddressMode addressV)
        {
            m_layers[static_cast<int>(layer)].m_sampler.UAddress = addressU;
            m_layers[static_cast<int>(layer)].m_sampler.VAddress = addressV;
        }

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerMapAddress(
            Layer layer,
            SamplerDefinition::EAddressMode addressU,
            SamplerDefinition::EAddressMode addressV,
            SamplerDefinition::EAddressMode addressW)
        {
            m_layers[static_cast<int>(layer)].m_sampler.UAddress = addressU;
            m_layers[static_cast<int>(layer)].m_sampler.VAddress = addressV;
            m_layers[static_cast<int>(layer)].m_sampler.WAddress = addressW;
        }

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerMapOffset(Layer layer, float uOffset, float vOffset)
        {
            m_layers[static_cast<int>(layer)].m_sampler.UOffset = uOffset;
            m_layers[static_cast<int>(layer)].m_sampler.VOffset = vOffset;
        }

        //---------------------------------------------------------------------
        inline void MaterialMaker::SetLayerMapTiling(Layer layer, float uTiling, float vTiling)
        {
            m_layers[static_cast<int>(layer)].m_sampler.UTiling = uTiling;
            m_layers[static_cast<int>(layer)].m_sampler.VTiling = vTiling;
        }

        //---------------------------------------------------------------------
        // M E S H   M A K E R   I N L I N E S
        //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        inline const float* MeshMaker::GetPositions() const
        {
            SpectreAssertExpr(m_lockedVertexData.m_positionData != nullptr, "MeshMaker::SetPostion - no position data");
            return m_lockedVertexData.m_positionData;
        }

        //---------------------------------------------------------------------
        inline const uint32_t* MeshMaker::GetIndices() const
        {
            SpectreAssertExpr(m_lockedVertexData.m_indexData != nullptr, "MeshMaker::SetIndices - no index data");
            return m_lockedVertexData.m_indexData;
        }

        //---------------------------------------------------------------------
        inline float* MeshMaker::GetNormals()
        {
            SpectreAssertExpr(m_lockedVertexData.m_normalData != nullptr, "MeshMaker::SetNormal - no normal data");
            return m_lockedVertexData.m_normalData;
        }

        //---------------------------------------------------------------------
        inline uint32_t MeshMaker::GetVertexCount() const
        {
            return m_lockedVertexData.m_numVerticesLocked;
        }

        //---------------------------------------------------------------------
        inline uint32_t MeshMaker::GetIndexCount() const
        {
            return m_lockedVertexData.m_numIndicesLocked;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetPosition(uint32_t vertexIndex, float x, float y, float z)
        {
            SpectreAssertExpr(vertexIndex < m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetPostion - invalid vertex");
            SpectreAssertExpr(m_lockedVertexData.m_positionData != nullptr, "MeshMaker::SetPostion - no position data");
            float* data = &m_lockedVertexData.m_positionData[vertexIndex * 3];
            data[0] = x; data[1] = y; data[2] = z;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetPositions(Utils::Math::Vector3 const* pPositions, uint32_t numPositions)
        {
            SpectreAssertExpr(pPositions != nullptr, "MeshMaker::SetPositions - invalid (null) pPositions");
            SpectreAssertExpr(numPositions == m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetPositions - invalid position count");
            SpectreAssertExpr(m_lockedVertexData.m_positionData != nullptr, "MeshMaker::SetPositions - no position data");
            memcpy(m_lockedVertexData.m_positionData, pPositions, sizeof(pPositions[0]) * numPositions);
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetNormal(uint32_t vertexIndex, float x, float y, float z)
        {
            SpectreAssertExpr(vertexIndex < m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetNormal - invalid vertex");
            SpectreAssertExpr(m_lockedVertexData.m_normalData != nullptr, "MeshMaker::SetNormal - no normal data");
            float* data = &m_lockedVertexData.m_normalData[vertexIndex * 3];
            data[0] = x; data[1] = y; data[2] = z;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetNormals(Utils::Math::Vector3 const* pNormals, uint32_t numNormals)
        {
            SpectreAssertExpr(pNormals != nullptr, "MeshMaker::SetPositions - invalid (null) pNormals");
            SpectreAssertExpr(numNormals == m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetNormals - invalid normal count");
            SpectreAssertExpr(m_lockedVertexData.m_normalData != nullptr, "MeshMaker::SetNormals - no normal data");
            memcpy(m_lockedVertexData.m_normalData, pNormals, sizeof(pNormals[0]) * numNormals);
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetTangent(uint32_t vertexIndex, float x, float y, float z, float w)
        {
            SpectreAssertExpr(vertexIndex < m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetTangent - invalid vertex");
            SpectreAssertExpr(m_lockedVertexData.m_tangentData != nullptr, "MeshMaker::SetTangent - no tangent data");
            float* data = &m_lockedVertexData.m_tangentData[vertexIndex * 4];
            data[0] = x; data[1] = y; data[2] = z; data[3] = w;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetColor(uint32_t vertexIndex, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        {
            SpectreAssertExpr(vertexIndex < m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetColor - invalid vertex");
            SpectreAssertExpr(m_lockedVertexData.m_colorData != nullptr, "MeshMaker::SetColor - no color data");
            uint8_t* data = (uint8_t*)&m_lockedVertexData.m_colorData[vertexIndex];
            data[0] = r; data[1] = g; data[2] = b; data[3] = a;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetUV0(uint32_t vertexIndex, float u, float v)
        {
            SpectreAssertExpr(vertexIndex < m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetUV0 - invalid vertex");
            SpectreAssertExpr(m_lockedVertexData.m_uvData[0] != nullptr, "MeshMaker::SetUV0 - no normal data");
            float* data = &m_lockedVertexData.m_uvData[0][vertexIndex * 2];
            data[0] = u; data[1] = v;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetUV1(uint32_t vertexIndex, float u, float v)
        {
            SpectreAssertExpr(vertexIndex < m_lockedVertexData.m_numVerticesLocked, "MeshMaker::SetUV1 - invalid vertex");
            SpectreAssertExpr(m_lockedVertexData.m_uvData[1] != nullptr, "MeshMaker::SetUV1 - no normal data");
            float* data = &m_lockedVertexData.m_uvData[1][vertexIndex * 2];
            data[0] = u; data[1] = v;
        }

        //---------------------------------------------------------------------

        inline void MeshMaker::SetIndices(uint32_t const* indices, uint32_t numIndices)
        {
            SpectreAssertExpr(indices != nullptr, "MeshMaker::SetPositions - invalid (null) indices");
            auto size = 0;
            if (m_areIndices32bit)
            {
                size = sizeof(uint32_t) * numIndices;
            }
            else
            {
                size = sizeof(uint16_t) * numIndices;
            }

            SpectreAssertExpr(numIndices == m_lockedVertexData.m_numIndicesLocked, "MeshMaker::SetIndices - invalid index count");
            SpectreAssertExpr(m_lockedVertexData.m_indexData != nullptr, "MeshMaker::SetIndices - no index data");
            memcpy(m_lockedVertexData.m_indexData, indices, size);
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetBlendInfo(uint32_t vertexIndex, int blendIndex, uint16_t jointIndex, float jointWeight)
        {
            m_lockedVertexData.m_jointWeights[vertexIndex * 4 + blendIndex] = (uint8_t)(255.0f * jointWeight);
            m_lockedVertexData.m_jointIndices[vertexIndex * 4 + blendIndex] = (uint8_t)jointIndex;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetLocalToParentTransform(const float* pMatrix44)
        {
            m_writer->SetTransform(pMatrix44);
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetLocalToParentTransform(const double* pMatrix44)
        {
            float local[16];
            for (int i = 0; i < 16; ++i)
                local[i] = (float)pMatrix44[i];

            m_writer->SetTransform(local);
        }

        inline const float* MeshMaker::GetLocalToParentTransform()
        {
            return m_writer->GetTransform();
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetBoundingBox(const float* pBoundingBox)
        {
            memcpy(m_boundingBox, pBoundingBox, sizeof(float) * 6);
            m_hasBoundingBox = true;
        }

        //---------------------------------------------------------------------
        inline const float* MeshMaker::GetBoundingBox()
        {
            return m_boundingBox;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetDisabled()
        {
            m_flags |= MeshSegment::Flags::kDisabled;
        }

        //---------------------------------------------------------------------
        inline void MeshMaker::SetFlags(uint16_t flags)
        {
            m_flags |= flags;
        }

    } // End namespace Framework

} // End namespace Spectre
