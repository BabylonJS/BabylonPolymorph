/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <Framework/GeometryUtils.h>
#include <CoreUtils/Assert.h>
#include <CoreUtils/Trace.h>
#include <CoreUtils/ITelemetryManager.h>
#include <CoreUtils/StreamUtils.h>
#include <CoreUtils/StringUtils.h>

#include <TranscoderPLY/PLYParser.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>

#include <sstream>
#include <string>

namespace DXSM = Babylon::Utils::Math;
namespace ST = Babylon::Transcoder;

DEFINE_TRACE_AREA(PLYParser, 0);

namespace
{
    const uint64_t PLYMinimumValidLength = 15;

    ST::LineTypeTranslator<ST::PLYHeaderLineType> PLYHeaderLineTypeTranslator()
    {
        auto sharedMap = std::map<std::string, ST::PLYHeaderLineType>();
        sharedMap["ply"] = ST::PLYHeaderLineType::ply;
        sharedMap["format"] = ST::PLYHeaderLineType::format;
        sharedMap["comment"] = ST::PLYHeaderLineType::comment;
        sharedMap["element"] = ST::PLYHeaderLineType::element;
        sharedMap["property"] = ST::PLYHeaderLineType::property;
        sharedMap["obj_info"] = ST::PLYHeaderLineType::obj_info;
        sharedMap["end_header"] = ST::PLYHeaderLineType::end_header;
        return ST::LineTypeTranslator<ST::PLYHeaderLineType>(sharedMap);
    }

    ST::LineTypeTranslator<ST::PLYDataType> PLYDataTypeTranslator()
    {
        auto sharedMap = std::map<std::string, ST::PLYDataType>();
        sharedMap["invalid"] = ST::PLYDataType::Invalid;
        sharedMap["int8"] = ST::PLYDataType::Int8;
        sharedMap["int16"] = ST::PLYDataType::Int16;
        sharedMap["int32"] = ST::PLYDataType::Int32;
        sharedMap["uint8"] = ST::PLYDataType::Uint8;
        sharedMap["uint16"] = ST::PLYDataType::Uint16;
        sharedMap["uint32"] = ST::PLYDataType::Uint32;
        sharedMap["float32"] = ST::PLYDataType::Float32;
        sharedMap["float64"] = ST::PLYDataType::Float64;

        // old data type values for backwards compatability :)
        sharedMap["char"] = ST::PLYDataType::Int8;
        sharedMap["short"] = ST::PLYDataType::Int16;
        sharedMap["int"] = ST::PLYDataType::Int32;
        sharedMap["uchar"] = ST::PLYDataType::Uint8;
        sharedMap["ushort"] = ST::PLYDataType::Uint16;
        sharedMap["uint"] = ST::PLYDataType::Uint32;
        sharedMap["float"] = ST::PLYDataType::Float32;
        sharedMap["double"] = ST::PLYDataType::Float64;

        return ST::LineTypeTranslator<ST::PLYDataType>(sharedMap);
    };

    ST::LineTypeTranslator<ST::PLYVertexAttribute> PLYVertexAttributeTranslator()
    {
        auto sharedMap = std::map<std::string, ST::PLYVertexAttribute>();
        sharedMap["x"] = ST::PLYVertexAttribute::x;
        sharedMap["y"] = ST::PLYVertexAttribute::y;
        sharedMap["z"] = ST::PLYVertexAttribute::z;
        sharedMap["r"] = ST::PLYVertexAttribute::r;
        sharedMap["red"] = ST::PLYVertexAttribute::r;
        sharedMap["g"] = ST::PLYVertexAttribute::g;
        sharedMap["green"] = ST::PLYVertexAttribute::g;
        sharedMap["b"] = ST::PLYVertexAttribute::b;
        sharedMap["blue"] = ST::PLYVertexAttribute::b;
        sharedMap["nx"] = ST::PLYVertexAttribute::nx;
        sharedMap["ny"] = ST::PLYVertexAttribute::ny;
        sharedMap["nz"] = ST::PLYVertexAttribute::nz;
        sharedMap["texture_u"] = ST::PLYVertexAttribute::u;
        sharedMap["texture_v"] = ST::PLYVertexAttribute::v;
        return ST::LineTypeTranslator<ST::PLYVertexAttribute>(sharedMap);
    };

    inline int64_t StrToInt64(const std::string& str)
    {
        size_t read = 0;
        auto value = std::stoll(str, &read);

        if (read != str.length())
        {
            throw BabylonException("Failed to parse all characters of string.");
        }

        return value;
    }

    inline uint64_t StrToUint64(const std::string& str)
    {
        size_t read = 0;
        auto value = std::stoull(str, &read);

        if (read != str.length())
        {
            throw BabylonException("Failed to parse all characters of string.");
        }

        return value;
    }

    inline double StrToDouble(const std::string& str)
    {
        size_t read = 0;
        auto value = std::stod(str, &read);

        if (read != str.length())
        {
            throw BabylonException("Failed to parse all characters of string.");
        }

        return value;
    }
}

namespace Babylon
{
    namespace Transcoder
    {
        const ST::LineTypeTranslator<PLYHeaderLineType> PLYParser::m_headerLineTypeTranslator = PLYHeaderLineTypeTranslator();
        const ST::LineTypeTranslator<PLYDataType> PLYParser::m_dataTypeTranslator = PLYDataTypeTranslator();
        const ST::LineTypeTranslator<PLYVertexAttribute> PLYParser::m_vertexAttributeTranslator = PLYVertexAttributeTranslator();

        PLYParser::PLYParser(
            std::shared_ptr<TranscoderTextStream> spStream,
            IResourceServer* resourceServer,
            PercentageCompleteCallback percentageCallback,
            Babylon::Framework::ICancellationTokenPtr cancellationToken)
            : m_stream(spStream),
            m_resourceServer(resourceServer),
            m_percentageCallback(percentageCallback),
            m_PercentageComplete(0.0f),
            m_fileType(PLYFileType::UNKNOWN),
            m_hasVerts(false),
            m_hasNormals(false),
            m_hasUVs(false),
            m_material(std::make_shared<MaterialDescriptor>()),
            m_cancellationToken(cancellationToken)
        {
            if (m_cancellationToken == nullptr)
            {
                m_cancellationToken = Babylon::Framework::MakeNullCancellationToken();
            }

            m_streamLength = m_stream->GetSize();

            m_tokens.reserve(10);
        }

        void PLYParser::AddVertex(DXSM::Vector3& vertex)
        {
            m_vertices.push_back(vertex);
        }

        void PLYParser::ComputeNormals()
        {
            if (m_vertices.size() > 0)
            {
                const float* vertexs = &(m_vertices[0].x);
                const uint32_t* indices = m_indices.data();

                const uint32_t outputVertexCount = static_cast<uint32_t>(m_vertices.size());
                const uint32_t outputIndexCount = static_cast<uint32_t>(m_indices.size());

                m_normals.resize(outputVertexCount);
                auto d = &(m_normals[0].x);

                Babylon::Framework::GeometryUtils::ComputeNormals(vertexs, outputVertexCount, indices, outputIndexCount, d);
            }
        }

        void PLYParser::UpdateProgressAndCheckCancellation()
        {
            // Update percentage completion callback
            if (m_percentageCallback != nullptr)
            {
                auto position = static_cast<float>(m_stream->GetPosition());
                m_PercentageComplete =  position / static_cast<float>(m_streamLength);
                m_percentageCallback(m_PercentageComplete);
            }

            m_cancellationToken->CheckCancelledAndThrow();
        }

        void PLYParser::AddFileType(const std::vector<std::string>& tokens)
        {
            m_fileType = PLYFileType::UNKNOWN;

            if (tokens.size() > 1)
            {
                std::string fileEncoding;
                if (tokens[1] == "ascii")
                {
                    m_fileType = PLYFileType::ASCII;
                    fileEncoding = "ASCII";
                    TRACE_IMPORTANT(PLYParser, "FileType: ASCII");
                }
                else if (tokens[1] == "binary_little_endian")
                {
                    m_fileType = PLYFileType::BINARYLITTLEENDIAN;
                    fileEncoding = "BINARY";
                    TRACE_IMPORTANT(PLYParser, "FileType: BINARY_LITTLE_ENDIAN");
                }
                else if (tokens[1] == "binary_big_endian")
                {
                    m_fileType = PLYFileType::BINARYBIGENDIAN;
                    fileEncoding = "BINARY";
                    TRACE_IMPORTANT(PLYParser, "FileType: BINARY_BIG_ENDIAN");
                }

#if FEATURE_TELEMETRYENABLED
                if (auto telemetryManager = Babylon::Utils::TelemetrySingleton::get())
                {
                    StringBuffer buffer;
                    Writer<StringBuffer> writer(buffer);
                    writer.StartObject();
                    writer.Key("FileFormat");
                    writer.String("ply");
                    writer.Key("FileEncoding");
                    writer.String(fileEncoding.c_str());
                    writer.EndObject();

                    telemetryManager->SendEvent("fileEncodingInformation", buffer.GetString());
                }
#endif
            }
        }

        void PLYParser::AddElement(const std::vector<std::string>& tokens)
        {
            if (tokens.size() >= 3)
            {
                PlyElement element;
                element.name = tokens[1];
                element.num = static_cast<int>(StrToUint64(tokens[2]));

                m_elements.push_back(element);
                TRACE_IMPORTANT(PLYParser, "Element : %s - %d", element.name.c_str(), element.num);
            }
        }

        void PLYParser::AddProperty(const std::vector<std::string>& tokens)
        {
            PlyProperty property;
            bool validProperty = false;

            if (tokens[1] == "list")
            {
                if (tokens.size() > 4)
                {
                    property.type = PLYPropertyType::LIST;
                    property.externalCountType = m_dataTypeTranslator.LookUp(tokens[2]);
                    property.externalDataType = m_dataTypeTranslator.LookUp(tokens[3]);
                    property.name = tokens[4];
                    validProperty = true;
                    TRACE_IMPORTANT(PLYParser, "\tProperty : %s - LIST", property.name.c_str());
                }
            }
            else if (tokens[1] == "string")
            {
                if (tokens.size() > 2)
                {
                    property.type = PLYPropertyType::STRING;
                    property.externalCountType = ST::PLYDataType::Int8;
                    property.externalDataType = ST::PLYDataType::Int8;
                    property.name = tokens[2];
                    validProperty = true;
                    TRACE_IMPORTANT(PLYParser, "\tProperty : %s - STRING", property.name.c_str());
                }
            }
            else if (tokens.size() > 2) // scalar value
            {
                property.type = PLYPropertyType::SCALAR;
                property.externalDataType = m_dataTypeTranslator.LookUp(tokens[1]);
                property.name = tokens[2];
                validProperty = true;
                TRACE_IMPORTANT(PLYParser, "\tProperty : %s - SCALAR", property.name.c_str());
            }

            // add this property to the list of properties of the current element e.g. the last element
            if (validProperty &&
                m_elements.size() > 0)
            {
                m_elements[m_elements.size() - 1].properties.push_back(property);
            }
        }

        bool PLYParser::ParseHeader()
        {
            while (!m_stream->EndOfStream())
            {
                m_tokens = ReadTokens();

                if (ProcessHeaderLine())
                {
                    return true;
                }
            }

            UpdateProgressAndCheckCancellation();

            return false;
        }

        std::vector<std::string> PLYParser::ReadTokens() const
        {
            char buffer[1024] = {};
            m_stream->ReadLine(buffer, 1024);

            return ParseTokens(buffer);
        }

        // Split a line into words, e.g. "a b   c \t\t       d" becomes {"a", "b", "c", "d"}
        std::vector<std::string> PLYParser::ParseTokens(const char* line) const
        {
            std::vector<std::string> tokens;

            std::string word;
            std::istringstream iss(line);
            iss.imbue(std::locale::classic());
            while (iss >> word)
            {
                tokens.push_back(word);
            }

            return tokens;
        }

        // Returns true once "end_header" has been reached, otherwise populates member variables with header metadata
        bool PLYParser::ProcessHeaderLine()
        {
            if (m_tokens.size() == 0)
            {
                return false;
            }

            auto lineType = m_headerLineTypeTranslator.LookUp(m_tokens[0]);
            switch (lineType)
            {
            case PLYHeaderLineType::end_header:
                return true;

            case PLYHeaderLineType::format:
                AddFileType(m_tokens);
                break;

            case PLYHeaderLineType::comment:
            {
                if ((m_tokens.size() >= 3) && m_tokens[1] == "TextureFile")
                {
                    auto textureFileName = m_tokens[2];
                    TRACE_IMPORTANT(PLYParser, "Texture Reference: %s", textureFileName.c_str());
                    if (!textureFileName.empty())
                    {
                        if (m_resourceServer)
                        {
                            // Only create a new texture descriptor if the texture data is available
                            if (auto textureStream = m_resourceServer->RequestResource(textureFileName))
                            {
                                size_t textureSize = 0;
                                auto textureData = Babylon::Utils::ReadStreamIntoUniquePtr(*textureStream, textureSize);

                                auto texture = std::make_shared<TextureDescriptor>(std::move(textureData), textureSize);
                                texture->SetName(textureFileName);

                                m_material->GetOrAddLayer(LayerType::kDiffuse)->Texture = texture;
                            }
                        }
                    }
                }

                break;
            }

            case PLYHeaderLineType::element:
                AddElement(m_tokens);
                break;

            case PLYHeaderLineType::property:
                AddProperty(m_tokens);
                break;

            case PLYHeaderLineType::obj_info: // ignore additional object information for now
            default:                          // unknown header field
                break;
            }

            return false;
        }

        bool get_ascii_item(
            const std::string& word,
            PLYDataType type,
            int64_t *int_val,
            uint64_t *uint_val,
            float *float_val
        )
        {
            switch (type) {
            case ST::PLYDataType::Int8:
            case ST::PLYDataType::Int16:
            case ST::PLYDataType::Int32:
                *int_val = StrToInt64(word);
                *uint_val = *int_val >= 0 ? *int_val : 0;
                *float_val = static_cast<float>(*int_val);
                break;

            case ST::PLYDataType::Uint8:
            case ST::PLYDataType::Uint16:
            case ST::PLYDataType::Uint32:
                *uint_val = StrToUint64(word);
                *int_val = *uint_val;
                *float_val = static_cast<float>(*uint_val);
                break;

            case ST::PLYDataType::Float32:
            case ST::PLYDataType::Float64:
                *float_val = static_cast<float>(StrToDouble(word));
                *int_val = static_cast<int>(*float_val);
                *uint_val = *float_val >= 0.0f ? static_cast<unsigned int>(*float_val) : 0;
                break;

            default:
                fprintf(stderr, "get_ascii_item_iter: bad type = %d\n", type);
                return false;
            }

            return true;
        }

        template<typename T>
        T SafeRead(std::shared_ptr<TranscoderTextStream> stream)
        {
            T value = 0;
            stream->Read(reinterpret_cast<char*>(&value), sizeof(T));
            return value;
        }

        uint8_t get_binary_item(
            std::shared_ptr<TranscoderTextStream> stream,
            size_t begPtr,
            size_t endPtr,
            PLYDataType type,
            bool bigEndian,
            int64_t *int_val,
            uint64_t *uint_val,
            float *float_val
        )
        {
            union
            {
                uint8_t bytes[2];
                int16_t int_val;
                uint16_t uint_val;
            } num16;

            union
            {
                uint8_t bytes[4];
                int32_t int_val;
                uint32_t uint_val;
                float float_val;
            } num32;

            switch (type) {
            case ST::PLYDataType::Int8:
            {
                if (endPtr - begPtr < 1) return 0;
                *int_val = SafeRead<int8_t>(stream);
                *uint_val = *int_val;
                *float_val = static_cast<float>(*int_val);
                return 1;
            }
            case ST::PLYDataType::Uint8:
            {
                if (endPtr - begPtr < 1) return 0;
                *uint_val = SafeRead<uint8_t>(stream);
                *int_val = *uint_val;
                *float_val = static_cast<float>(*uint_val);
                return 1;
            }
            case ST::PLYDataType::Int16:
            {
                if (endPtr - begPtr < 2) return 0;
                num16.int_val = SafeRead<int16_t>(stream);
                if (bigEndian)
                {
                    std::swap(num32.bytes[0], num32.bytes[1]);
                }
                *uint_val = num16.uint_val;
                *int_val = num16.int_val;
                *float_val = static_cast<float>(num16.int_val);
                return 2;
            }
            case ST::PLYDataType::Uint16:
            {
                if (endPtr - begPtr < 2) return 0;
                num16.uint_val = SafeRead<uint16_t>(stream);
                if (bigEndian)
                {
                    std::swap(num32.bytes[0], num32.bytes[1]);
                }
                *uint_val = num16.uint_val;
                *int_val = num16.int_val;
                *float_val = static_cast<float>(num16.int_val);
                return 2;
            }
            case ST::PLYDataType::Int32:
            {
                if (endPtr - begPtr < 4) return 0;
                num32.int_val = SafeRead<int32_t>(stream);

                if (bigEndian)
                {
                    std::swap(num32.bytes[0], num32.bytes[3]);
                    std::swap(num32.bytes[1], num32.bytes[2]);
                }
                *uint_val = num32.uint_val;
                *int_val = num32.int_val;
                *float_val = num32.float_val;
                return 4;
            }
            case ST::PLYDataType::Uint32:
            {
                if (endPtr - begPtr < 4) return 0;
                num32.uint_val = SafeRead<uint32_t>(stream);
                if (bigEndian)
                {
                    std::swap(num32.bytes[0], num32.bytes[3]);
                    std::swap(num32.bytes[1], num32.bytes[2]);
                }
                *uint_val = num32.uint_val;
                *int_val = num32.int_val;
                *float_val = num32.float_val;
                return 4;
            }
            case ST::PLYDataType::Float32:
            {
                if (endPtr - begPtr < 4) return 0;
                num32.float_val = SafeRead<float>(stream);
                if (bigEndian)
                {
                    std::swap(num32.bytes[0], num32.bytes[3]);
                    std::swap(num32.bytes[1], num32.bytes[2]);
                }
                *float_val = num32.float_val;
                *int_val = num32.int_val;
                *uint_val = num32.uint_val;
                return 4;
            }
            case ST::PLYDataType::Float64:
                if (endPtr - begPtr < 8) return 0;
                union
                {
                    uint8_t bytes[8];
                    int64_t int_val;
                    uint64_t uint_val;
                    double float_val;
                } num64;
                num64.float_val = SafeRead<double>(stream);
                if (bigEndian)
                {
                    std::swap(num64.bytes[0], num64.bytes[3]);
                    std::swap(num64.bytes[1], num64.bytes[2]);

                    std::swap(num64.bytes[4], num64.bytes[7]);
                    std::swap(num64.bytes[5], num64.bytes[6]);
                }
                *float_val = static_cast<float>(num64.float_val);
                *int_val = num64.int_val;
                *uint_val = num64.uint_val;
                return 8;
            default:
                return 0;
            }
        }

        void PLYParser::GetElement(
            PlyElement& element,
            std::function<void(std::string, int64_t, uint64_t, float)> scalarCallback,
            std::function<void(std::string, size_t, int64_t, uint64_t, float)> listCallback,
            std::function<void(std::string, std::string)> stringCallback)
        {
            UpdateProgressAndCheckCancellation();

            if (m_fileType == PLYFileType::ASCII)
            {
                m_tokens = ReadTokens();

                for (size_t i = 0, tk = 0;
                    (tk < m_tokens.size() && i < element.properties.size());
                    i++)
                {
                    uint64_t uint_value = 0;
                    int64_t  int_value = 0;
                    float float_value = 0;

                    auto prop = element.properties[i];
                    if (prop.type == PLYPropertyType::SCALAR &&
                        scalarCallback != nullptr)
                    {
                        // read and convert to valid type
                        get_ascii_item(m_tokens[tk], prop.externalDataType, &int_value, &uint_value, &float_value);
                        tk++;
                        scalarCallback(prop.name, int_value, uint_value, float_value);
                    }
                    else if (prop.type == PLYPropertyType::LIST &&
                        listCallback != nullptr)
                    {
                        // first item is always the count
                        get_ascii_item(m_tokens[tk], prop.externalCountType, &int_value, &uint_value, &float_value);
                        uint64_t count = uint_value;
                        tk++;

                        for (int j = 0;
                            (tk < m_tokens.size() && j < count);
                            j++, tk++)
                        {
                            get_ascii_item(m_tokens[tk], prop.externalDataType, &int_value, &uint_value, &float_value);
                            listCallback(prop.name, j, int_value, uint_value, float_value);
                        }

                    }
                    else if (prop.type == PLYPropertyType::STRING &&
                        stringCallback != nullptr)
                    {
                        stringCallback(prop.name, m_tokens[tk]);
                        tk++;
                    }
                }
            }
            else
            {
                // Binary
                bool bigEndian = (m_fileType == PLYFileType::BINARYBIGENDIAN);
                size_t curPtr = m_stream->GetPosition();
                size_t endPtr = m_stream->GetSize();

                for (size_t i = 0;
                    (i < element.properties.size() && curPtr != endPtr);
                    i++)
                {
                    curPtr = m_stream->GetPosition();

                    uint64_t uint_value = 0;
                    int64_t  int_value = 0;
                    float float_value = 0;

                    auto prop = element.properties[i];
                    if (prop.type == PLYPropertyType::SCALAR)
                    {
                        get_binary_item(m_stream, curPtr, endPtr, prop.externalDataType, bigEndian, &int_value, &uint_value, &float_value);
                        if (scalarCallback != nullptr)
                        {
                            scalarCallback(prop.name, int_value, uint_value, float_value);
                        }
                    }
                    else if (prop.type == PLYPropertyType::LIST)
                    {
                        // first item is always the count
                        get_binary_item(m_stream, curPtr, endPtr, prop.externalCountType, bigEndian, &int_value, &uint_value, &float_value);
                        uint64_t count = uint_value;

                        for (int j = 1;
                            (j <= count && curPtr != endPtr);
                            j++)
                        {
                            get_binary_item(m_stream, curPtr, endPtr, prop.externalDataType, bigEndian, &int_value, &uint_value, &float_value);
                            if (listCallback != nullptr)
                            {
                                listCallback(prop.name, j, int_value, uint_value, float_value);
                            }
                        }
                    }
                    else if (prop.type == PLYPropertyType::STRING &&
                        stringCallback != nullptr)
                    {
                        // first item is always the count
                        get_binary_item(m_stream, curPtr, endPtr, ST::PLYDataType::Int32, bigEndian, &int_value, &uint_value, &float_value);
                        if (stringCallback != nullptr)
                        {
                            auto str = std::vector<char>(static_cast<size_t>(uint_value));
                            m_stream->Read(str.data(), static_cast<size_t>(uint_value));
                            stringCallback(prop.name, std::string(str.begin(), str.end()));
                        }
                    }
                }
            }
        }

        std::shared_ptr<Asset3D> PLYParser::ParseStream()
        {
            ParseStreamInternal();
            return CreateAsset3d();
        }

        void PLYParser::ParseStreamToPly()
        {
            ParseStreamInternal();
        }

        std::shared_ptr<Asset3D> PLYParser::CreateAsset3d()
        {
            const auto& verts = GetVertices();
            const auto& normals = GetNormals();
            const auto& uvs = GetUVs();
            const auto& indices = GetIndices();

            if ((indices.size() % 3) != 0)
            {
                // Does this ever happen?
                TRACE_ERROR(PLYParser, "Warning an odd number of indices encountered, the end of the index list will be ignored.");
            }

            Geometry geo(m_material);

            geo.SetIndices(indices);
            FreeIndices();

            geo.SetPositions(verts);
            FreeVertices();

            geo.SetNormals(normals);
            FreeNormals();

            geo.SetUv0s(uvs);
            FreeUVs();

            std::shared_ptr<Asset3D> asset = std::make_shared<Asset3D>();

            asset->SetMesh(std::make_shared<Mesh>(std::move(geo)));

            return asset;
        }

        void PLYParser::ParseStreamInternal()
        {
            if (m_streamLength <= PLYMinimumValidLength)
            {
                char errorMsg[512];
                sprintf_s(errorMsg, "File Length Invalid : %llu <= %llu", m_streamLength, PLYMinimumValidLength);
                throw Utils::BabylonException(errorMsg);
            }

            if (!ParseHeader())
            {
                throw Utils::BabylonException("Invalid Header");
            }

            size_t numberOfVerts = 0;
            size_t numberOfFaces = 0;

            for (auto &element : m_elements)
            {
                if (element.name == "vertex")
                {
                    numberOfVerts = element.num;
                    // check for presence data e.g. vertex must have atleast x,y,z
                    for (auto &prop : element.properties)
                    {
                        if (prop.type == PLYPropertyType::SCALAR)
                        {
                            switch (m_vertexAttributeTranslator.LookUp(prop.name))
                            {
                            case PLYVertexAttribute::x:
                            case PLYVertexAttribute::y:
                            case PLYVertexAttribute::z: m_hasVerts = true; break;

                            case PLYVertexAttribute::nx:
                            case PLYVertexAttribute::ny:
                            case PLYVertexAttribute::nz: m_hasNormals = true; break;

                            case PLYVertexAttribute::u:
                            case PLYVertexAttribute::v: m_hasUVs = true; break;

                            default: break;  // Do nothing
                            }
                        }
                    }
                }

                if (element.name == "face")
                {
                    // indices
                    numberOfFaces = element.num;
                }
            }

            if (!m_hasVerts || numberOfFaces == 0)
            {
                throw Utils::BabylonException("PLY files with vertices but no indices are not supported");
            }

            if (m_hasVerts)
            {
                m_vertices.reserve(numberOfVerts); // assuming all faces are triangles
                m_indices.reserve(numberOfVerts * 3);
            }

            if (m_hasUVs)
            {
                m_uvs.reserve(numberOfVerts); // assuming all faces are triangles
            }

            // read each of the elements in turn
            for (auto &element : m_elements)
            {
                if (element.name == "vertex")
                {
                    //read vertexes
                    for (int i = 0; i < element.num; i++)
                    {
                        DXSM::Vector3 vert;
                        DXSM::Vector2 uv;

                        GetElement(element, [&vert, &uv](
                            std::string name,
                            uint64_t uint_value,
                            int64_t  int_value,
                            float float_value)
                        {
                            BabylonUnusedParameter(uint_value);
                            BabylonUnusedParameter(int_value);

                            switch (m_vertexAttributeTranslator.LookUp(name))
                            {
                            case PLYVertexAttribute::x: vert.x = float_value; break;
                            case PLYVertexAttribute::y: vert.y = float_value; break;
                            case PLYVertexAttribute::z: vert.z = float_value; break;

                            case PLYVertexAttribute::u: uv.x = float_value; break;
                            case PLYVertexAttribute::v: uv.y = (1 - float_value); break;

                            case PLYVertexAttribute::nx: // Normals ignored!
                            case PLYVertexAttribute::ny:
                            case PLYVertexAttribute::nz:

                            default:
                                break;
                            }
                        });

                        AddVertex(vert);

                        if (m_hasUVs)
                            m_uvs.push_back(uv);

                    }
                    continue;
                }

                if (element.name == "face")
                {
                    for (int i = 0; i < element.num; i++)
                    {
                        // for now just read the indicies out;
                        std::vector<uint32_t> face;
                        uint32_t vertCount = 0;

                        vertCount = 0;
                        face.clear();

                        GetElement(element, nullptr, [&face, &vertCount](
                            std::string name,
                            size_t index,
                            uint64_t uint_value,
                            int64_t  int_value,
                            float float_value)
                        {
                            if (name == "vertex_indices" ||
                                name == "vertex_index")
                            {
                                BabylonUnusedParameter(index);
                                BabylonUnusedParameter(int_value);
                                BabylonUnusedParameter(float_value);

                                face.push_back(static_cast<uint32_t>(uint_value));
                                vertCount++;
                            }
                        }, nullptr);

                        // Ensure indicies are inbounds of vert count
                        for (size_t k = 0; k < face.size(); k++)
                        {
                            if (face[k] >= numberOfVerts)
                            {
                                throw Utils::BabylonException(
                                    std::string("OOB Index - ") +
                                    std::to_string(face[k]) + " >= " +
                                    std::to_string(numberOfVerts));
                            }
                        }

                        if (face.size() > 2)
                        {
                            // ensure all Polys are triangulated
                            for (size_t j = 2; j < face.size(); j++)
                            {
                                m_indices.push_back(face[0]);
                                m_indices.push_back(face[j - 1]);
                                m_indices.push_back(face[j]);
                            }
                        }
                    }
                    continue;
                }

                if (element.name == "material")
                {
                    // TODO : Not yet found a ply with materials
                }

                // read remaining lines and ignore
                TRACE_INFO(PLYParser, "Unsupported Element : %s", element.name.c_str());
                for (int i = 0; i < element.num; i++)
                {
                    GetElement(element);
                }
            }

            ComputeNormals();

            if (m_percentageCallback != nullptr)
            {
                // report parser complete
                m_percentageCallback(1.0f);
            }
        }
    } // namespace Transcoder
} // namespace Babylon
