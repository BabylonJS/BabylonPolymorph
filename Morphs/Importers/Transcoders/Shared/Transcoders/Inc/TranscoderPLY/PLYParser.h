/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <tuple>
#include <bitset>

#include <Framework/GeometryUtils.h>
#include <PluginSDK/FileParserBase.h>
#include <PluginSDK/LineTokensPtr.h>
#include <PluginSDK/LineTypeTranslator.h>
#include <Asset3D/Asset3D.h>

using namespace Spectre::Utils;
namespace DXSM = Spectre::Utils::Math;
namespace ST = Spectre::Transcoder;

namespace Spectre
{
    namespace Transcoder
    {
        enum class PLYHeaderLineType
        {
            unknown = 0,
            ply,
            format,
            comment,
            element,
            property,
            obj_info,
            end_header,
            plyheaderMax,
        };

        enum class PLYFileType
        {
            ASCII = 0,
            BINARYBIGENDIAN = 1,
            BINARYLITTLEENDIAN = 2,
            UNKNOWN = 3
        };

        enum class PLYPropertyType
        {
            SCALAR = 0,
            LIST   = 1,
            STRING = 2
        };

        enum class PLYDataType
        {
            Invalid = 0,
            Int8 = 1,
            Int16 = 2,
            Int32 = 3,
            Uint8 = 4,
            Uint16 = 5,
            Uint32 = 6,
            Float32 = 7,
            Float64 = 8,
            KDataTypeMax = 9
        };

        enum class PLYVertexAttribute
        {
            x = 1,
            y = 2,
            z = 3,
            r = 4,
            g = 5,
            b = 6,
            nx = 7,
            ny = 8,
            nz = 9,
            u = 10,
            v = 11
        };

        typedef struct PlyProperty
        {
            std::string name;             /* property name */
            PLYPropertyType type;          /* property types */
            PLYDataType externalDataType;
            PLYDataType internalDataType;
            PLYDataType externalCountType;
            PLYDataType internalCountType;
        } PlyProperty;

        typedef struct PlyElement
        {
            std::string name;             /* element name */
            int num;                      /* number of elements in this object */
            int size;                     /* size of element (bytes) or -1 if variable */
            std::vector<PlyProperty> properties;  /* list of properties in the file */
        } PlyElement;

        typedef std::function<void(float percentage)> PercentageCompleteCallback;

        class PLYParser
        {
            public:
                explicit PLYParser(
                    std::shared_ptr<TranscoderTextStream> spStream,
                    IResourceServer* resourceServer = nullptr,
                    PercentageCompleteCallback percentageCallback = nullptr,
                    Framework::ICancellationTokenPtr cancellationToken = nullptr);

                std::shared_ptr<Asset3D> ParseStream();

                //V2 two step parsing allows us to free the stream sooner lowering peak memory usage
                void ParseStreamToPly();
                std::shared_ptr<Asset3D> CreateAsset3d();

                // Internals
                bool ParseHeader();
                std::vector<std::string> ParseTokens(const char* line) const;

                void AddFileType(const std::vector<std::string>& tokens);
                void AddElement(const std::vector<std::string>& tokens);
                void AddProperty(const std::vector<std::string>& tokens);

                const std::vector<PlyElement> GetElements() const { return m_elements; }
                const PLYFileType GetFileType() const { return m_fileType; }

                const std::vector<DXSM::Vector3>& GetVertices() const { return m_vertices; }
                const std::vector<uint32_t>& GetIndices() const { return m_indices; }
                const std::vector<DXSM::Vector3>& GetNormals() const { return m_normals; }
                const std::vector<DXSM::Vector2>& GetUVs() const { return m_uvs; }

        private:
                std::vector<std::string> ReadTokens() const;
                bool ProcessHeaderLine();

                void GetElement(
                    PlyElement& element,
                    std::function<void(std::string, int64_t, uint64_t, float)> scalarCallback = nullptr,
                    std::function<void(std::string, size_t, int64_t, uint64_t, float)> listCallback = nullptr,
                    std::function<void(std::string, std::string)> stringCallback = nullptr);

                void UpdateProgressAndCheckCancellation();

                void AddVertex(DXSM::Vector3& vertex);
                void ComputeNormals();

                // Accessors
                void FreeVertices() { std::vector<DXSM::Vector3>().swap(m_vertices); }
                void FreeNormals() { std::vector<DXSM::Vector3>().swap(m_normals); }
                void FreeIndices() { std::vector<uint32_t>().swap(m_indices); }
                void FreeUVs() { std::vector<DXSM::Vector2>().swap(m_uvs); }
                void ParseStreamInternal();         // for now, we read the entire object, used to generate an Asset3D obj, in future we may be able to stream straight from to the other.
                                                    // so we hide this detail
                std::shared_ptr<TranscoderTextStream> m_stream;
                IResourceServer* m_resourceServer;

                PercentageCompleteCallback m_percentageCallback;
                float m_PercentageComplete;

                static const ST::LineTypeTranslator<PLYHeaderLineType> m_headerLineTypeTranslator;
                static const ST::LineTypeTranslator<PLYDataType> m_dataTypeTranslator;
                static const ST::LineTypeTranslator<PLYVertexAttribute> m_vertexAttributeTranslator;

                std::vector<std::string> m_tokens;

                uint64_t m_streamLength;

                // File Descriptor
                PLYFileType m_fileType;
                std::vector<PlyElement> m_elements;

                bool m_hasVerts;
                bool m_hasNormals;
                bool m_hasUVs;

                std::vector<DXSM::Vector3> m_vertices;
                std::vector<DXSM::Vector3> m_normals;
                std::vector<DXSM::Vector2> m_uvs;
                std::vector<uint32_t> m_indices;

                std::shared_ptr<MaterialDescriptor> m_material;
                Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}
