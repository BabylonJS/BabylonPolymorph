/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/MeshMaker.h>
#include <Framework/SceneWriter.h>
#include <Framework/TextureWriter.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Math/SpectreMath.h>

DEFINE_TRACE_AREA(MeshMaker, 0);

namespace Spectre
{
    namespace Framework
    {
        //-----------------------------------------------------------------------------

        DataMaker::DataMaker(
            EncodeBGRAFunc encodeFunc,
            int textureCompression,
            EByteOrder outputByteOrder,
            ConverterLODMode textureLODMode)
            : m_byteOrder(outputByteOrder),
            m_textureCompression(textureCompression),
            m_textureLODMode(textureLODMode),
            m_encodeFunc(encodeFunc)
        {
        }

        //-----------------------------------------------------------------------------

        DataMaker::DataMaker(
            EncodeBGRAFunc encodeFunc,
            EncodeRAWBGRAFunc rawEncodeFunc,
            int textureCompression,
            EByteOrder outputByteOrder,
            ConverterLODMode textureLODMode)
            : m_byteOrder(outputByteOrder),
            m_textureCompression(textureCompression),
            m_textureLODMode(textureLODMode),
            m_encodeFunc(encodeFunc),
            m_rawEncodeFunc(rawEncodeFunc)
        {
        }

        //-----------------------------------------------------------------------------

        DataMaker::~DataMaker()
        {
        }

        //-----------------------------------------------------------------------------
        std::shared_ptr<MeshMaker> DataMaker::CreateMesh(
            const char* name,
            const char* parentName,
            const char* materialName,
            uint32_t numVertices,
            uint32_t numIndices,
            uint32_t vertexFormatMask,
            GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
            ProcessMeshCallback createMeshCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            // need to namespace to avoid aliasing between meshes and nodes (MeshMaker is used for nodes as well as meshes)
            std::string meshName = std::string(name) + ".mesh";
            std::string parentNameStr; // (need to keep this in the outer scope to avoid pParentName dangling)
            if (parentName)
            {
                parentNameStr = std::string(parentName) + ".node";
                parentName = parentNameStr.c_str();
            }

            TRACE_IMPORTANT(MeshMaker, "CreateMesh: %s->%s (material:%s)", parentName, name, materialName);

            auto meshMaker = std::make_shared<MeshMaker>(
                meshName.c_str(),
                parentName,
                materialName,
                numVertices,
                numIndices,
                vertexFormatMask,
                meshAnalysisResults,
                createMeshCB);

            m_meshes.push_back(meshMaker);
            RegisterName(meshName.c_str(), meshMaker->GetID());
            return meshMaker;
        }

        //-----------------------------------------------------------------------------

        std::shared_ptr<MeshMaker> DataMaker::CreateMesh(
            const char* name,
            uint32_t id,
            uint32_t parentId,
            uint32_t materialId,
            uint32_t numVertices,
            uint32_t numIndices,
            bool areIndices32bit,
            uint32_t vertexFormatMask,
            GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
            ProcessMeshCallback createMeshCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);
            std::string meshName = std::string(name) + ".mesh";

            TRACE_IMPORTANT(MeshMaker, "CreateMesh: parendId=%u->meshId=%u (materialId=%u)", parentId, id, materialId);

            auto mesh = std::make_shared<MeshMaker>(
                name,
                id,
                parentId,
                materialId,
                numVertices,
                numIndices,
                areIndices32bit,
                vertexFormatMask,
                meshAnalysisResults,
                createMeshCB);

            m_meshes.push_back(mesh);
            RegisterName(meshName, mesh->GetID());
            return mesh;
        }

        //-----------------------------------------------------------------------------
        MeshMakerPtr DataMaker::CreateEmptyNode(
            const char* name,
            const char* parentName,
            ProcessMeshCallback createNodeCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            // need to namespace to avoid aliasing between meshes and nodes (MeshMaker is used for nodes as well as meshes)
            std::string nameStr = std::string(name) + ".node";
            std::string parentNameStr; // (need to keep this in the outer scope to avoid pParentName dangling)
            if (parentName)
            {
                parentNameStr = std::string(parentName) + ".node";
                parentName = parentNameStr.c_str();
            }

            TRACE_IMPORTANT(MeshMaker, "CreateEmptyNode: %s->%s", parentName, nameStr.c_str());

            auto meshMaker = std::make_shared<MeshMaker>(
                nameStr.c_str(),
                parentName,
                createNodeCB);

            m_meshes.push_back(meshMaker);
            RegisterName(name, meshMaker->GetID());
            return meshMaker;
        }

        //-----------------------------------------------------------------------------
        MeshMakerPtr DataMaker::CreateEmptyNode(
            const char* name,
            uint32_t id,
            uint32_t parentId,
            ProcessMeshCallback createNodeCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            std::string strName = name;
            strName = strName.append(".node");

            TRACE_IMPORTANT(MeshMaker, "CreateEmptyNode: %u->%u", parentId, id);

            auto mesh = std::make_shared<MeshMaker>(
                name,
                id,
                parentId,
                createNodeCB);

            m_meshes.push_back(mesh);
            RegisterName(name, mesh->GetID());
            return mesh;
        }

        //-----------------------------------------------------------------------------
        MaterialMakerPtr DataMaker::CreateMaterial(
            const char* name,
            ProcessMaterialCallback createMaterialCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "CreateMaterial: %s", name);

            auto materialMaker = std::make_shared<MaterialMaker>(name, createMaterialCB);
            auto id = materialMaker->GetID();

            MaterialIterator it = m_materials.find(id);
            if (it != m_materials.end())
            {
                // Materials are assigned a unique ID, so there should be no duplicates!
                // Duplicate material. Skip it...
                TRACE_WARN(MeshMaker, "Duplicate material found.");
                return it->second;
            }
            TRACE_IMPORTANT(MeshMaker, "Material Name: %s Material ID: %u", name, id);
            RegisterName(name, id);
            m_materials[id] = materialMaker;
            return materialMaker;
        }

        //-----------------------------------------------------------------------------
        MaterialMakerPtr DataMaker::CreateMaterial(
            const char* name,
            uint32_t id,
            ProcessMaterialCallback createMaterialCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "CreateMaterial: %u", id);

            auto mat = std::make_shared<MaterialMaker>(name, id, createMaterialCB);

            MaterialIterator it = m_materials.find(id);
            if (it != m_materials.end())
            {
                // Materials are assigned a unique ID, so there should be no duplicates!
                // Duplicate material. Skip it...
                TRACE_WARN(MeshMaker, "Duplicate material found.");
                return it->second;
            }
            TRACE_IMPORTANT(MeshMaker, "MaterialId: %u", id);
            RegisterName(name, id);
            m_materials[id] = mat;
            return mat;
        }

        //-----------------------------------------------------------------------------
        TextureMakerPtr DataMaker::CreateTexture(
            const char* name,
            std::string const& path,
            std::ifstream&& inputStream,
            ProcessTextureCallback createTextureCB,
            TextureMaterialLayer layer,
            float scaleFactor)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "CreateTexture(stream): %s (%s)", name, path.c_str());

            auto reader = PathToImageReader(path);
            auto textureMaker = std::make_shared<TextureMaker>(
                name,
                path,
                reader,
                std::forward<std::ifstream>(inputStream),
                createTextureCB,
                m_textureCompression);

            if (m_textureLODMode == ConverterLODMode::kNoLOD)
            {
                textureMaker->SetLODProcessingAlgorithm(TextureLOD::kOriginalOnly);
            }
            else
            {
                textureMaker->SetLODProcessingAlgorithm(TextureLOD::k3Level);
            }

            textureMaker->SetTextureLayer(layer);
            textureMaker->SetScaleFactor(scaleFactor);

            auto id = textureMaker->GetID();

            TextureIterator it = m_textures.find(id);
            if (it != m_textures.end())
            {
                // :TODO: Error/change ID
                // Duplicate material. Skip it...
                return it->second;
            }

            RegisterName(name, id);
            m_textures[id] = textureMaker;
            return textureMaker;
        }

        //-----------------------------------------------------------------------------
        TextureMakerPtr DataMaker::CreateTexture(
            const char* name,
            std::string const& path,
            std::unique_ptr<uint8_t[]>&& data,
            uint32_t dataSizeInBytes,
            ProcessTextureCallback createTextureCB,
            TextureMaterialLayer layer,
            float scaleFactor)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "CreateTexture(byte[]): %s (%s)", name, path.c_str());

            auto reader = PathToImageReader(path);
            auto textureMaker = std::make_shared<TextureMaker>(
                name,
                path,
                reader,
                std::move(data),
                dataSizeInBytes,
                m_textureCompression,
                0);

            if (m_textureLODMode == ConverterLODMode::kNoLOD)
                textureMaker->SetLODProcessingAlgorithm(TextureLOD::kOriginalOnly);
            else
                textureMaker->SetLODProcessingAlgorithm(TextureLOD::k3Level);

            textureMaker->SetTextureLayer(layer);
            textureMaker->SetScaleFactor(scaleFactor);

            auto id = textureMaker->GetID();

            TextureIterator it = m_textures.find(id);
            if (it != m_textures.end())
            {
                // :TODO: Error/change ID
                // Duplicate material. Skip it...
                return it->second;
            }

            RegisterName(name, id);
            m_textures[id] = textureMaker;
            return textureMaker;
        }

        //-----------------------------------------------------------------------------
        TextureMakerPtr DataMaker::CreateTexture(
            const char* name,
            uint32_t id,
            std::unique_ptr<uint8_t[]>&& data,
            uint32_t    width,
            uint32_t    height,
            uint32_t    lineStride,
            uint32_t    size,
            Framework::TextureSegment::EFormat format,
            uint8_t flags,
            TextureMaterialLayer layer,
            float scaleFactor)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            auto textureMaker = std::make_shared<TextureMaker>(
                name,
                id,
                std::move(data),
                width,
                height,
                lineStride,
                size,
                format,
                flags);

            textureMaker->SetTextureCompression(m_textureCompression);
            textureMaker->SetTextureLayer(layer);
            textureMaker->SetScaleFactor(scaleFactor);

            TextureIterator it = m_textures.find(id);
            if (it != m_textures.end())
            {
                // :TODO: Error/change ID
                // Duplicate material. Skip it...
                return it->second;
            }

            RegisterName(name, id);
            m_textures[id] = textureMaker;
            return textureMaker;
        }

        //-----------------------------------------------------------------------------
        void DataMaker::RemoveTexture(uint32_t id, OnFrameCallback callback)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "RemoveTexture: %u", id);

            TextureIterator it = m_textures.find(id);
            if (it != m_textures.end())
            {
                m_textures.erase(it);
            }

            TryProcessTextureLODs(callback);
        }

        //-----------------------------------------------------------------------------
        uint32_t DataMaker::CreateTextureDelayed(
            const char* name,
            std::string const& path,
            ProcessTextureCallback createTextureCB)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "CreateTextureDelayed: %s (%s)", name, path.c_str());

            auto reader = PathToImageReader(path);
            auto textureMaker = std::make_shared<TextureMaker>(
                name,
                path,
                reader,
                createTextureCB,
                m_textureCompression);

            if (m_textureLODMode == ConverterLODMode::kNoLOD)
                textureMaker->SetLODProcessingAlgorithm(TextureLOD::kOriginalOnly);
            else
                textureMaker->SetLODProcessingAlgorithm(TextureLOD::k3Level);

            auto id = textureMaker->GetID();

            TextureIterator it = m_textures.find(id);
            if (it != m_textures.end())
            {
                // :TODO: Error/change ID
                // Duplicate material. Skip it...
                return 0;
            }
            else
            {
                m_textures[id] = textureMaker;
            }

            RegisterName(name, id);
            return textureMaker->GetID();
        }

        //-----------------------------------------------------------------------------
        void DataMaker::UpdateDelayedTexture(
            uint32_t textureId,
            std::unique_ptr<uint8_t[]>&& data,
                                                        uint32_t dataSizeInBytes,
                                                        OnFrameCallback callback)
        {
            std::lock_guard<std::mutex> lock(m_lock);

            TRACE_IMPORTANT(MeshMaker, "UpdateDelayedTexture: %u", textureId);

            TextureIterator it = m_textures.find(textureId);
            if (it != m_textures.end())
            {
                auto textureMaker = it->second;

                if (textureMaker->IsWaitingForData())
                {
                    textureMaker->SetDelayedData(std::move(data), dataSizeInBytes);
                }
            }

            TryProcessTextureLODs(callback);
        }

//-----------------------------------------------------------------------------

        void DataMaker::CreateTextureLODWriters(TextureWriters& writers)
        {
            int count[(int)Framework::TextureLOD::kMaxMips] = { 0 };

            // If all texture have arrived, process them....
            for (auto const& texture : m_textures)
            {
                // If there's any textures still waiting for data, then cannot flush yet...
                // :TODO: This can be slightly improved. Basically, we can flush lower level MIPS, if they have all arrived, since
                // for example, the texture waiting data may only require high level mips, etc...
                if (texture.second->IsWaitingForData())
                    return;

                // Keep track of how many of each mip, so that we can optimize the serialization
                int numMips = TextureLODToNumMips(texture.second->GetLODProcessingAlgorithm());
                for (int j = 0; j < numMips; ++j)
                    count[j]++;
            }

            // All textures have arrived.

            // Create the writers...
            // To be clear:
            //  writers[0] is for HIGH level LOD data
            //  writers[1] is for MEDIUM level LOD data
            //  writers[2] is for LOW level LOD data
            Framework::EFrameQuality quality[(int)Framework::TextureLOD::kMaxMips] =
            {
                Framework::EFrameQuality::kHigh,
                Framework::EFrameQuality::kMedium,
                Framework::EFrameQuality::kLow
            };

            writers.reserve((int)Framework::TextureLOD::kMaxMips);
            for (int i = 0; i < (int)Framework::TextureLOD::kMaxMips; ++i)
            {
                // Only create a writer if there are any textures destined for it....

                if (count[i] > 0)
                {
                    auto writer = Framework::TextureWriterCreate(m_encodeFunc);
                    auto bufferPtr = std::make_shared<Framework::MemoryBuffer>();
                    writer->BeginFrame(bufferPtr, count[i], m_byteOrder, quality[i]);
                    writers.push_back(writer);
                }
            }
        }

        //-----------------------------------------------------------------------------

        void DataMaker::ProcessTextures(OnFrameCallback callback)
        {
            if (m_rawEncodeFunc != nullptr)
            {
                TextureWriters writers;
                CreateTextureLODWriters(writers);

                for (TextureIterator it = m_textures.begin(); it != m_textures.end(); ++it)
                {
                    it->second->CreateRAWTextureLOD(writers, m_rawEncodeFunc);
                }

                for (TextureWritersRevIterator it = writers.rbegin(); it != writers.rend(); ++it)
                {
                    auto frame = (*it)->EndFrame();

                    std::string metadataJSON = "";

                    callback(frame, metadataJSON);

                    Framework::TextureWriterDestroy(*it);
                }
            }
            else
            {
                // No re-encoding function available simply write raw texture
                for (auto texture : m_textures)
                {
                    auto writer = Framework::TextureWriterCreate(m_encodeFunc);
                    auto buffer = new Framework::MemoryBuffer();
                    auto bufferPtr = std::shared_ptr<Framework::MemoryBuffer>(buffer);
                    writer->BeginFrame(bufferPtr, 1, m_byteOrder, Framework::EFrameQuality::kHigh);

                    texture.second->CreateTextureEncoded(writer);

                    auto frame = writer->EndFrame();
                    std::string metadataJSON;
                    callback(frame, metadataJSON);
                    Framework::TextureWriterDestroy(writer);
                }
            }
        }


        //-----------------------------------------------------------------------------
        void DataMaker::PreprocessMeshes()
        {
            MeshContainer rootMeshes;
            for (auto mesh : m_meshes)
            {
                // If the parent ID is 0 then the mesh is attached to the
                // root node of a layer. We want to gather these meshes in
                // order to attach them to an intermediate node that contains
                // the bounds of the combined meshes.
                if (mesh->GetParentID() == 0)
                {
                    rootMeshes.push_back(mesh);
                }
            }

            // Apply a scene root node to the model. This will contain the scale and the
            // bounding box.
            // Generate unique parent ID
            uint32_t rootID = 0;
            uint32_t parentID = 0;

            // Create a new root node for the root meshes. This will contain the scale factor
            // to fit the model within the unit area viewing volume. (See MeshMaker::FitMeshToViewingVolume)
            {
                std::string strName = "Root";
                strName = strName.append(".node");
                rootID = Utils::Hash(strName.c_str());

                TRACE_IMPORTANT(MeshMaker, "CreateEmptyNode: %u->%u", parentID, rootID);

                auto newRootMesh = std::make_shared<MeshMaker>(
                    strName.c_str(),
                    rootID,
                    parentID,
                    [](Spectre::Framework::MeshMaker* maker) { SpectreUnusedParameter(maker); });

                m_meshes.insert(std::begin(m_meshes), newRootMesh);
                RegisterName(strName.c_str(), newRootMesh->GetID());
            }

            // Now add the re-centering node to the model.
            // To do this we create another node to attach to the root node
            // with the given transform to correctly recenter the model.
            // The re-center node will be parented to the above root node
            {
                parentID = rootID;
                std::string strName = "Re-center Root Node";
                strName = strName.append(".node");
                rootID = Utils::Hash(strName.c_str());

                TRACE_IMPORTANT(MeshMaker, "CreateEmptyNode: %u->%u", parentID, rootID);

                auto reCentreTransform = Utils::Math::Matrix::CreateTranslation({ -m_rootBounds.Center.x, -m_rootBounds.Center.y, -m_rootBounds.Center.z });
                auto reCenterMesh = std::make_shared<MeshMaker>(
                    strName.c_str(),
                    rootID,
                    parentID,
                    [reCentreTransform](Spectre::Framework::MeshMaker* maker)
                {
                    // When this mesh is loaded we want to set its transform to re-center the node.
                    maker->SetLocalToParentTransform(reinterpret_cast<const float*>(reCentreTransform.m));
                });

                // Insert it after the first mesh. i.e. after the new root mesh.
                m_meshes.insert(++std::begin(m_meshes), reCenterMesh);
                RegisterName(strName.c_str(), reCenterMesh->GetID());
            }

            // Update all root meshes to point towards the correct node.
            // If the model did not need to be re-centered the root meshes will
            // point to the new Root Node
            // If the model did need to be re-centered the root meshes will point
            // to the Re-center Root Node.
            for (auto rootMesh : rootMeshes)
            {
                rootMesh->SetParentId(rootID);
            }
        }

        //-----------------------------------------------------------------------------

        void DataMaker::TryProcessTextureLODs(OnFrameCallback callback)
        {
            TextureWriters writers;
            CreateTextureLODWriters(writers);

            for (TextureIterator it = m_textures.begin(); it != m_textures.end(); ++it)
            {
                it->second->CreateTextureLOD(writers, m_encodeFunc);
            }

            for (TextureWritersRevIterator it = writers.rbegin(); it != writers.rend(); ++it)
            {
                auto frame = (*it)->EndFrame();

                std::string metadataJSON = "";

                callback(frame, metadataJSON);

                Framework::TextureWriterDestroy(*it);
            }
        }

        //-----------------------------------------------------------------------------
        void MeshMaker::FitMeshToViewingVolume(DirectX::BoundingBox bounds)
        {
            // The scale factor applied to the scene so that the scene's maximum extent
            // (longest axis) is scaled to fit two world units, and its half extent fits one world unit.
            // For example, if the scene's longest axis was 10 world units, then its half extent is 5, so ScaleFactor will be 1/5 == 0.2.
            // Calculate scaling factor
            SpectreAssert(bounds.Extents.x != 0);
            SpectreAssert(bounds.Extents.y != 0);
            SpectreAssert(bounds.Extents.z != 0);

            float scaleX = 1.0f / (bounds.Extents.x * 2.0f);
            float scaleY = 1.0f / (bounds.Extents.y * 2.0f);
            float scaleZ = 1.0f / (bounds.Extents.z * 2.0f);

            float scale = std::min(scaleX, std::min(scaleY, scaleZ));

            auto transform = GetLocalToParentTransform();
            Utils::Math::Matrix transformMatrix(transform);
            Vector3 scaleComponent = Vector3::Zero;
            Utils::Math::Quaternion rotationComponent = Utils::Math::Quaternion::Identity;
            Vector3 translationComponent = Vector3::Zero;

            // Matrix must be affine and finite in order to correctly decompose the matrix
            if (MatrixIsAffine(transformMatrix) && MatrixIsFinite(transformMatrix))
            {
                transformMatrix.Decompose(scaleComponent, rotationComponent, translationComponent);
                // We don't want to store the translation after the model has been scaled down and re-centred
                translationComponent = Vector3::Zero;
            }

            // If the scale component is zero then we want to set it directly rather than multiplying it.
            if (scaleComponent == Vector3::Zero)
            {
                // If the scale component is zero. This could have been set purposefully, or the matrix could be
                // empty. We next check to see if it is affine. If not then we will overwrite the scale component directly.
                if (MatrixIsAffine(transformMatrix) == false)
                {
                    scaleComponent = Vector3(scale);
                }
            }
            else
            {
                scaleComponent *= scale;
            }

            auto scaleTransform = Utils::Math::Matrix::CreateScale(scaleComponent);
            auto boundsScaleTransform = Utils::Math::Matrix::CreateScale(scale);
            // Now we scale the bounding box since we have scaled the mesh.
            DirectX::BoundingBox scaledBounds;
            bounds.Transform(scaledBounds, boundsScaleTransform);
            bounds = scaledBounds;
            auto rotationTransform = Utils::Math::Matrix::CreateFromQuaternion(rotationComponent);
            auto translationTransform = Utils::Math::Matrix::CreateTranslation(translationComponent);

            // Currently in the viewer we don't read the rotation or translation
            // from the root node of a BXF stream however we set them here to avoid losing data.
            transformMatrix = scaleTransform * rotationTransform * translationTransform;

            // After the model has been scaled and re-centred the bounding box centre should be at the origin.
            bounds.Center = Vector3::Zero;
            float boundsArray[6] = { bounds.Center.x, bounds.Center.y, bounds.Center.z,
                bounds.Extents.x, bounds.Extents.y, bounds.Extents.z };

            SetBoundingBox(boundsArray);
            SetLocalToParentTransform(reinterpret_cast<float*>(transformMatrix.m));
        }

        //-----------------------------------------------------------------------------
        void DataMaker::RegisterName(
            const std::string& nameStr,
            uint32_t id)
        {
#if FEATURE_ENABLE_METADATA_FRAMES
            NameMappingIterator it = m_nameMap.find(id);
            if (it != m_nameMap.end())
            {
                // Clash?
                if (it->second == nameStr)
                {
                    return; // Same name, maps to same ID. We're ok.
                }

                SpectreAssertExpr(false, "DataMaker::RegisterName: Name and ID clash");
                return;
            }

            m_nameMap[id] = std::move(nameStr);
#else
            SpectreUnusedParameter(nameStr);
            SpectreUnusedParameter(id);
#endif
        }

        //-----------------------------------------------------------------------------
        void DataMaker::SetSceneOptions(float scaleFactor, float systemUnitInCentimetres)
        {
            m_scene.ScaleFactor = scaleFactor;
            m_scene.SystemUnit = systemUnitInCentimetres;
        }


        //-----------------------------------------------------------------------------
        void DataMaker::SetRootBounds(DirectX::BoundingBox rootBounds)
        {
            m_rootBounds = rootBounds;
        }

        //-----------------------------------------------------------------------------
        void DataMaker::Emit(OnFrameCallback callback, Spectre::Framework::ICancellationTokenPtr cancellationToken)
        {
            if (cancellationToken == nullptr)
            {
                cancellationToken = Spectre::Framework::MakeCancellationToken();
            }

            std::lock_guard<std::mutex> lock(m_lock);

            SpectreAssertExpr(callback != nullptr, "DataMaker::Emit - callback not set");

            // Output all materials first (they are small compared to meshes)
            if (m_materials.size() > 0)
            {
                auto writer = Framework::MaterialWriterCreate();
                auto buffer = new Framework::MemoryBuffer();

                auto bufferPtr = std::shared_ptr<Framework::MemoryBuffer>(buffer);

                // :TODO: Make a pass over all the materials to uniquify the samplers...

                // All materials go in 1 frame

                writer->BeginFrame(bufferPtr, (uint32_t)m_materials.size(), m_byteOrder);

                MaterialIterator endIt = m_materials.end();
                for (MaterialIterator it = m_materials.begin(); it != endIt; ++it)
                {
                    it->second->CreateMaterial(writer);
                }
                Frame* frame = writer->EndFrame();

                std::string metadataJSON = "";

                callback(frame, metadataJSON);

                Framework::MaterialWriterDestroy(writer);
            }

            cancellationToken->CheckCancelledAndThrow();

            // Output all meshes
            if (m_meshes.size() > 0)
            {
                // When serializing from the engine scene we can export a selection of nodes/meshes
                // without a common parent. Here we process the given meshes and create a common parent
                // if necessary. At the same time we will apply an offset to re-centre the scene if
                // it is not at the origin.
                PreprocessMeshes();

                auto writer = Framework::GeometryWriterCreate();
                auto buffer = new Framework::MemoryBuffer();
                auto bufferPtr = std::shared_ptr<Framework::MemoryBuffer>(buffer);

                MeshIterator endIt = m_meshes.end();
                for (MeshIterator it = m_meshes.begin(); it != endIt; ++it)
                {
                    cancellationToken->CheckCancelledAndThrow();

                    // :TODO: Begin frame (For now this is fine. Since we have global visibility over the data, we
                    // can optimize the mesh output generation)

                    writer->BeginFrame(bufferPtr, 1, m_byteOrder);

                    auto mesh = *it;

                    TRACE_IMPORTANT(MeshMaker, "Emitting mesh '%s' with parent '%s'",
                                    mesh->m_name.c_str(),
                                    mesh->m_parentName.c_str());


                    DirectX::BoundingBox bounds(Vector3::Zero, Vector3::Zero);
                    if (mesh->GetParentID() == 0)
                    {
                        if (Vector3::Zero != m_rootBounds.Extents)
                        {
                            bounds = m_rootBounds;
                        }
                        else if (mesh->m_hasBoundingBox)
                        {
                            auto boundsArray = mesh->GetBoundingBox();
                            bounds.Center = { boundsArray[0], boundsArray[1], boundsArray[2] };
                            bounds.Extents = { boundsArray[3], boundsArray[4], boundsArray[5] };
                        }
                    }

                    mesh->CreateMesh(writer, bounds);

                    auto frame = writer->EndFrame();

                    auto meshAnalysisResults = mesh->GetMeshAnalysisResults();

                    std::stringstream metadataJSON;
                    metadataJSON << "{";
                    metadataJSON << "\"VertCount\":" << mesh->GetNumVertices() << ",";
                    metadataJSON << "\"TriCount\":" << mesh->GetNumIndices() / 3 << ",";

                    // This is oddly phrased in order to produce an aggregate result such as: "MeshCount":10,"WatertightCount":7
                    // which would express that 7 / 10 sub-meshes are watertight (int metadata fields are summed at the moment)
                    metadataJSON << "\"MeshCount\":1,";
                    metadataJSON << "\"WatertightCount\":" << (meshAnalysisResults.IsWatertight() ? 1 : 0);
                    metadataJSON << "}";

                    callback(frame, metadataJSON.str());

                    // Reset buffer

                    buffer->Reset();
                }

                Framework::GeometryWriterDestroy(writer);
            }

            // Output Scene frame next -- this is currently unconditional (always written)
            {
                ISceneWriter* writer = Framework::SceneWriterCreate();
                auto buffer = new Framework::MemoryBuffer();
                auto bufferPtr = std::shared_ptr<Framework::MemoryBuffer>(buffer);

                int sceneCount = 1;
                int cameraCount = 0; // Reserved for future expansion

                auto itemCount = sceneCount + cameraCount;

                writer->BeginFrame(bufferPtr, itemCount, m_byteOrder);
                writer->AddScene(m_scene);

                // future expansion: flush cameras here

                try
                {
                    auto frame = writer->EndFrame();

                    std::string metadataJSON;

                    callback(frame, metadataJSON);
                }
                catch (const Utils::SpectreException&)
                {
                    TRACE_IMPORTANT(MeshMaker, "Exception has been thrown during scene writer's EndFrame call");
                }

                Framework::SceneWriterDestroy(writer);
            }

#if FEATURE_ENABLE_METADATA_FRAMES
            // Output Metadata frame next
            if (m_nameMap.size() > 0)
            {
                m_cancellationToken->CheckCancelledAndThrow();

                IMetadataWriter* writer = Framework::MetadataWriterCreate();
                auto buffer = new Framework::MemoryBuffer();

                auto bufferPtr = std::shared_ptr<Framework::MemoryBuffer>(buffer);

                writer->BeginFrame(bufferPtr, (uint32_t)m_nameMap.size(), m_byteOrder);

                NameMappingIterator endIt = m_nameMap.end();
                for (NameMappingIterator it = m_nameMap.begin(); it != endIt; ++it)
                {
                    writer->BeginMetadata(it->first, it->second.c_str());
                    writer->EndMetadata();
                }

                auto frame = writer->EndFrame();

                std::string metadataJSON = "";

                callback(frame, metadataJSON);

                Framework::MetadataWriterDestroy(writer);
            }
#endif

            cancellationToken->CheckCancelledAndThrow();

            if (m_encodeFunc != nullptr)
            {
                TryProcessTextureLODs(callback);
            }
            else
            {
                ProcessTextures(callback);
            }
        }

        //-----------------------------------------------------------------------------

        ImageReader DataMaker::PathToImageReader(std::string const& path)
        {
            std::string normalisedPath = path;
            Utils::TransformToLower(normalisedPath);

            ImageReader reader = ImageReader::WIC;
            if (Utils::EndsWith(normalisedPath, ".dds"))
            {
                reader = ImageReader::DDS;
            }
            else if (Utils::EndsWith(normalisedPath, ".tga"))
            {
                reader = ImageReader::TGA;
            }
            return reader;
        }


        //-----------------------------------------------------------------------------
        // MESH MAKER
        //-----------------------------------------------------------------------------

        //-----------------------------------------------------------------------------
        MeshMaker::MeshMaker(
            const char* name,
            const char* parentName,
            const char* materialName,
            uint32_t numVertices,
            uint32_t numIndices,
            uint32_t formatMask,
            GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
            ProcessMeshCallback callback)
            :
            m_name(name),
            m_id(Spectre::Utils::Hash(name)),
            m_numVertices(numVertices),
            m_numIndices(numIndices),
            m_formatMask(formatMask),
            m_meshAnalysisResults(meshAnalysisResults)
        {
            if (parentName != nullptr)
            {
                m_parentId = Spectre::Utils::Hash(parentName);
                m_parentName = parentName;
            }
            if (materialName != nullptr)
            {
                m_materialId = Spectre::Utils::Hash(materialName);
                m_materialName = materialName;
            }
            m_callbacks.push_back(callback);
        }

        //-----------------------------------------------------------------------------
        MeshMaker::MeshMaker(
            const char* name,
            uint32_t id,
            uint32_t parentId,
            uint32_t materialId,
            uint32_t numVertices,
            uint32_t numIndices,
            bool areIndices32bit,
            uint32_t formatMask,
            Spectre::Framework::GeometryUtils::TriangleMeshAnalysisResults meshAnalysisResults,
            ProcessMeshCallback callback)
            :
            m_name(name),
            m_id(id),
            m_parentId(parentId),
            m_materialId(materialId),
            m_numVertices(numVertices),
            m_numIndices(numIndices),
            m_formatMask(formatMask),
            m_areIndices32bit(areIndices32bit),
            m_meshAnalysisResults(meshAnalysisResults)
        {
            m_callbacks.push_back(callback);

            m_name = std::to_string(m_id);
        }

        //-----------------------------------------------------------------------------
        MeshMaker::MeshMaker(
            const char*         pName,
            const char*         pParentName,
            ProcessMeshCallback callback)
            :
            m_name(pName),
            m_id(Spectre::Utils::Hash(pName)),
            m_meshAnalysisResults(0)
        {
            if (pParentName != nullptr)
            {
                m_parentName = pParentName;
                m_parentId = Spectre::Utils::Hash(pParentName);
            }
            m_callbacks.push_back(callback);
        }

        //-----------------------------------------------------------------------------
        MeshMaker::MeshMaker(
            const char* name,
            uint32_t id,
            uint32_t parentId,
            ProcessMeshCallback callback)
            :
            m_name(name),
            m_id(id),
            m_parentId(parentId),
            m_meshAnalysisResults(0)
        {
            m_callbacks.push_back(callback);
        }

        //-----------------------------------------------------------------------------
        MeshMaker::~MeshMaker()
        {
        }

        //---------------------------------------------------------------------
        void MeshMaker::CreateMesh(IGeometryWriter* writer, DirectX::BoundingBox rootBounds)
        {
            SpectreAssertExpr(m_name.length() > 0, "MeshMaker::CreateMesh - No mesh name provided");
            uint32_t meshId = m_id;
            uint32_t parentId = m_parentId;
            uint32_t materialId = m_materialId;
            uint32_t skeletonId = m_skeletonId;

            TRACE_IMPORTANT(MeshMaker, "Mesh: Writing output for %s", m_name.c_str());

            m_writer = writer;

            // Begin the mesh
            m_writer->BeginMesh(meshId, parentId, materialId, skeletonId);

            if (m_numVertices > 0)
            {
                // Lock the vertex data
                m_lockedVertexData = m_writer->LockVertexData(m_numVertices, m_numIndices, m_formatMask, m_areIndices32bit);
            }

            // Process the mesh
            for (auto callback : m_callbacks)
            {
                callback(this);
            }

            // If we have bounds for this mesh then we can calculate the scale factor to apply to the
            // node and its subtree. Otherwise we leave the node alone.
            if (Vector3::Zero != rootBounds.Extents)
            {
                FitMeshToViewingVolume(rootBounds);
            }

            if (m_numVertices > 0)
            {
                // Unlock
                m_writer->UnlockVertexData(m_lockedVertexData);
            }

            if (m_hasBoundingBox)
            {
                m_writer->SetBoundingBox(&m_boundingBox[0], &m_boundingBox[3]);
            }

            m_writer->SetFlags(m_flags);

            // Close the mesh
            m_writer->EndMesh();
        }

        void MeshMaker::AllocateMeshBuffers(uint32_t vertexCount, uint32_t indexCount)
        {
            SpectreAssert(m_numVertices == 0);
            SpectreAssert(m_numIndices == 0);
            m_numVertices = vertexCount;
            m_numIndices = indexCount;
            m_lockedVertexData = m_writer->LockVertexData(vertexCount, indexCount, m_formatMask);
        }

        //---------------------------------------------------------------------
        // M A T E R I A L   M A K E R
        //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        MaterialMaker::MaterialMaker(const char* materialName, ProcessMaterialCallback callback)
            :
            m_name(materialName),
            m_id(Utils::Hash(materialName)),
            m_callback(callback)
        {
            InitAllLayers();
        }

        //---------------------------------------------------------------------
        MaterialMaker::MaterialMaker(
            const char* name,
            uint32_t materialId,
            ProcessMaterialCallback callback)
            :
            m_name(name),
            m_id(materialId),
            m_callback(callback),
            m_hashNames(false)
        {
            InitAllLayers();
        }

        //---------------------------------------------------------------------
        void MaterialMaker::InitAllLayers()
        {
            // Init all the layers, setting defaults for samplers...

            for (int i = 0; i < static_cast<int>(Layer::kNumLayers); ++i)
            {
                LayerInfo& l = m_layers[i];
                l.m_hasColor = false;
                l.m_color = 0;
                l.m_mapName.clear();

                SamplerDefinition& s = l.m_sampler;
                s.FilterMode = SamplerDefinition::EFilterMode::kBilinear;
                s.UAddress = s.VAddress = s.WAddress = SamplerDefinition::EAddressMode::kClamp;
                s.UOffset = s.VOffset = 0.0f;
                s.UTiling = s.VTiling = 1.0f;
                s.BorderColour = 0;
            }
        }

        //---------------------------------------------------------------------

        MaterialMaker::~MaterialMaker()
        {
        }

        //---------------------------------------------------------------------
        void MaterialMaker::CreateMaterial(IMaterialWriter* writer)
        {
            m_callback(this);

            TRACE_IMPORTANT(MeshMaker, "Material: Writing output for %s", m_name.c_str());

            writer->BeginMaterial(m_id);

            if (m_setHairShader)
            {
                writer->SetShaderType(MaterialDefinition::EShaderType::kHairShader);
            }

            writer->SetSpectreRenderingMode(m_spectreRenderingMode);
            writer->SetSpectreRenderingOptions(m_spectreRenderingOptions);

            { // ALBEDO (Diffuse or BaseColor)
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kAlbedo)];
                if (layer.m_hasColor || (layer.GetID() != 0))
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetDiffuseABGR(layer.m_color, mapId, layer.m_sampler);
                }
            }

            { // WORKFLOW (SpecularGlossiness or MetallicRoughness)
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kWorkflow)];
                if (layer.m_hasColor || (layer.GetID() != 0))
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetSpecularABGR(layer.m_color, mapId, layer.m_sampler);
                }
            }

            { // EMISSIVE
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kEmissive)];
                if (layer.m_hasColor || (layer.GetID() != 0))
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetEmissiveABGR(layer.m_color, mapId, layer.m_sampler, 1.0f);
                }
            }

            { // NORMAL
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kNormal)];
                if (layer.GetID() != 0)
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetNormal(mapId, layer.m_sampler);
                }
            }

            { // DEPTH
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kDepth)];
                if (layer.GetID() != 0)
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetDepth(mapId, layer.m_sampler);
                }
            }

            { // DETAIL
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kDetail)];
                if (layer.GetID() != 0)
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetDetail(mapId, layer.m_sampler);
                }
            }

            { // OCCLUSION
                LayerInfo& layer = m_layers[static_cast<int>(Layer::kOcclusion)];
                if (layer.GetID() != 0)
                {
                    uint32_t mapId = layer.GetID();
                    writer->SetOcclusion(mapId, layer.m_sampler);
                }
            }

            writer->EndMaterial();
        }

        //---------------------------------------------------------------------

        uint32_t MaterialMaker::LayerInfo::GetID() const
        {
            if (m_mapName.empty())
            {
                return m_id;
            }
            return Utils::Hash(m_mapName.c_str());
        }

        //---------------------------------------------------------------------
        // T E X T U R E   M A K E R
        //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        TextureMaker::TextureMaker(
            const std::string& name,
            const std::string& path,
            ImageReader reader,
            std::ifstream&& inputStream,
            ProcessTextureCallback callback,
            int textureCompression)
            :
            m_name(name),
            m_path(path),
            m_id(Utils::Hash(name.c_str())),
            m_lodProcessing(TextureLOD::kOriginalOnly),
            m_inputStream(std::move(inputStream)),
            m_delayedData(nullptr),
            m_delayedDataSizeInBytes(0),
            m_waitingForData(false),
            m_isDelayedTexture(false),
            m_writer(nullptr),
            m_reader(reader),
            m_textureCompression(textureCompression),
            m_textureLayer(TextureMaterialLayer::kDiffuse),
            m_scaleFactor(1.0f)
        {
        }

        //---------------------------------------------------------------------
        TextureMaker::TextureMaker(
            const std::string&      name,
            const std::string&      path,
            ImageReader             reader,
            ProcessTextureCallback  callback,
            int                     textureCompression
            ) :
            m_name(name),
            m_path(path),
            m_id(Utils::Hash(name.c_str())),
            m_lodProcessing(TextureLOD::kOriginalOnly),
            m_delayedData(nullptr),
            m_delayedDataSizeInBytes(0),
            m_waitingForData(true),
            m_isDelayedTexture(true),
            m_callback(callback),
            m_writer(nullptr),
            m_reader(reader),
            m_textureCompression(textureCompression),
            m_textureLayer(TextureMaterialLayer::kDiffuse),
            m_scaleFactor(1.0f)
        {
        }

        //---------------------------------------------------------------------
        TextureMaker::TextureMaker(
            const std::string&              name,
            const std::string&              path,
            ImageReader                     reader,
            std::unique_ptr<uint8_t[]>&&    pData,
            uint32_t                        sizeInBytes,
            int                             textureCompression,
            int                             reserved
            ) :
            m_name(name),
            m_path(path),
            m_id(Utils::Hash(name.c_str())),
            m_lodProcessing(TextureLOD::kOriginalOnly),
            m_delayedData(std::move(pData)),
            m_delayedDataSizeInBytes(sizeInBytes),
            m_waitingForData(false),
            m_isDelayedTexture(true),
            m_callback(nullptr),
            m_writer(nullptr),
            m_reader(reader),
            m_textureCompression(textureCompression),
            m_textureLayer(TextureMaterialLayer::kDiffuse),
            m_scaleFactor(1.0f)
        {
            SpectreUnusedParameter(reserved);
        }

        //---------------------------------------------------------------------

        TextureMaker::TextureMaker(
            const std::string&              name,
            uint32_t                        id,
            std::unique_ptr<uint8_t[]>&&    data,
            uint32_t                        width,
            uint32_t                        height,
            uint32_t                        lineStride,
            uint32_t                        size,
            Framework::TextureSegment::EFormat format,
            uint8_t                         flags) :
            m_name(name),
            m_id(id),
            m_lodProcessing(TextureLOD::kOriginalOnly),
            m_delayedData(std::move(data)),
            m_delayedDataSizeInBytes(size),
            m_height(height),
            m_width(width),
            m_lineStride(lineStride),
            m_format(format),
            m_flags(flags),
            m_waitingForData(false),
            m_isDelayedTexture(true),
            m_callback(nullptr),
            m_writer(nullptr),
            m_reader(ImageReader::UNKNOWN),
            m_textureLayer(TextureMaterialLayer::kDiffuse),
            m_scaleFactor(1.0f)
        {
        }

        //---------------------------------------------------------------------
        TextureMaker::~TextureMaker()
        {
            if (m_inputStream.is_open())
            {
                m_inputStream.close();
            }
        }

        //---------------------------------------------------------------------
        void TextureMaker::CreateTextureLOD(std::vector<ITextureWriter*>& writers, EncodeBGRAFunc encodeFunc)
        {
            if (m_isDelayedTexture)
            {
                TextureProcessingOptions options;
                options.LOD = GetLODProcessingAlgorithm();
                options.Reader = m_reader;
                options.TextureCompression = m_textureCompression;
                options.LayerType = m_textureLayer;
                options.ScaleFactor = m_scaleFactor;

                encodeFunc(m_name,
                           m_path,
                           m_id,
                           m_delayedData.get(),
                           m_delayedDataSizeInBytes,
                           writers,
                           options);
            }
            else
            {
                SpectreAssert(false); // :TODO:
            }
        }

        //---------------------------------------------------------------------

        void TextureMaker::CreateRAWTextureLOD(
                                std::vector<class ITextureWriter*>& writers,
                                EncodeRAWBGRAFunc rawEncodeFunc)
        {
            TextureProcessingOptions options;
            options.LOD = GetLODProcessingAlgorithm();
            options.Reader = m_reader;
            options.TextureCompression = m_textureCompression;
            options.LayerType = m_textureLayer;
            options.ScaleFactor = m_scaleFactor;

            rawEncodeFunc(
                m_id,
                m_width,
                m_height,
                m_lineStride,
                m_format,
                m_flags,
                m_delayedData.get(),
                m_delayedDataSizeInBytes,
                writers,
                options);
        }
        //---------------------------------------------------------------------

        void TextureMaker::CreateTextureEncoded(ITextureWriter* writer)
        {
            m_writer = writer;

            auto buffer = writer->AddTextureEncoded(
                m_id,
                m_width,
                m_height,
                m_lineStride / m_width,
                m_lineStride,
                m_delayedDataSizeInBytes,
                m_format,
                m_flags);

            memcpy_s(buffer,
                     m_delayedDataSizeInBytes,
                     m_delayedData.get(),
                     m_delayedDataSizeInBytes);
        }

        //---------------------------------------------------------------------

        void TextureMaker::CreateTexture(ITextureWriter* writer, uint32_t lod)
        {
            m_writer = writer;
            // If we have a stream process it...
            if (m_isDelayedTexture)
            {
                m_writer->AddTexture(
                    m_name,
                    m_path,
                    m_id,
                    m_reader,
                    m_delayedData.get(),
                    m_delayedDataSizeInBytes,
                    m_textureCompression,
                    lod);

                // Free the data
                m_delayedData = nullptr;

            }
            else if (m_inputStream.is_open())
            {
                // Go to the end of the file.
                m_inputStream.seekg(0, std::ios::end);

                // Find the file size.
                uint32_t size = static_cast<uint32_t>(m_inputStream.tellg());

                // Check max size.
                if (size > (1024 * 1024 * 100)) // 100MB limit
                {
                    return;
                }

                // Go back to the beginning of the file.
                m_inputStream.seekg(0, std::ios::beg);

                // Read the data in byte buffer.
                std::vector<char> buffer(size);
                if (!m_inputStream.read(buffer.data(), size))
                {
                    return;
                }

                m_writer->AddTexture(
                    m_name,
                    m_path,
                    m_id,
                    m_reader,
                    buffer.data(),
                    size,
                    m_textureCompression,
                    lod);
            }
        }

        //---------------------------------------------------------------------
        void TextureMaker::SetDelayedData(std::unique_ptr<uint8_t[]>&& pData, uint32_t sizeInBytes)
        {
            m_delayedData = std::move(pData);
            m_waitingForData = false;
            m_delayedDataSizeInBytes = sizeInBytes;
        }
        //---------------------------------------------------------------------
    }
}
