/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <Framework/GeometryUtils.h>

#include <Asset3D/Geometry.h>
#include <CoreUtils/StringUtils.h>
#include <PluginSDK/LineTypeTranslator.h>
#include <PluginSDK/TokenParser.h>
#include <TranscoderException.h>
#include <TranscoderOBJ/GeometryParser.h>
#include <TranscoderOBJ/GeometryLineType.h>
#include <TranscoderOBJ/AuthorType.h>
#include <TranscoderOBJ/MaterialParser.h>
#include <TranscoderOBJ/MtlTextureMapOptions.h>
#include <Asset3D/MaterialDescriptor.h>

using namespace Spectre::Transcoder;

namespace
{
    constexpr const char* kVertexDelimiter = "/";

    LineTypeTranslator<GeometryLineType> GeometryLineTypeTranslator()
    {
        auto sharedMap = std::map<std::string, GeometryLineType>();
        sharedMap["v"] = v;
        sharedMap["vt"] = vt;
        sharedMap["vn"] = vn;
        sharedMap["f"] = f;
        sharedMap["s"] = SmoothingGroupLine;
        sharedMap["mtllib"] = mtllib;
        sharedMap["usemtl"] = usemtl;
        sharedMap["#"] = comment;
        return LineTypeTranslator<GeometryLineType>(sharedMap);
    }

    LineTypeTranslator<AuthorType> AuthorTypeTranslator()
    {
        auto sharedMap = std::map<std::string, AuthorType>();
        sharedMap["123d"] = autodesk123D;
        sharedMap["blender"] = blender;
        return LineTypeTranslator<AuthorType>(sharedMap);
    }

    template<typename T>
    T GetElementFromObjStringIndex(const std::vector<T>& collection, const std::string& indexStr)
    {
        if (indexStr.empty())
        {
            throw Spectre::Utils::SpectreException("Invalid index: empty");
        }

        int64_t offset = std::stol(indexStr);
        size_t index = 0;
        if (offset > 0)
        {
            index = static_cast<size_t>(offset - 1);
        }
        else
        {
            index = static_cast<size_t>(collection.size() + offset);
        }

        if (index >= collection.size())
        {
            std::stringstream errorMsg;
            errorMsg << "Invalid index, out of bounds: " << index << " ('" << indexStr << "')";
            throw Spectre::Utils::SpectreException(errorMsg.str());
        }

        return collection[index];
    }

    Spectre::Utils::Math::Vector3 FlipYZ(const Spectre::Utils::Math::Vector3& vec3)
    {
        return Spectre::Utils::Math::Vector3(vec3.x, vec3.z, -vec3.y);
    }
}

DEFINE_TRACE_AREA(GeometryParser, 0);

const LineTypeTranslator<GeometryLineType> GeometryParser::m_lineTypeTranslator = GeometryLineTypeTranslator();
const LineTypeTranslator<AuthorType> GeometryParser::m_authorTypeTranslator = AuthorTypeTranslator();

GeometryParser::GeometryParser(
    IResourceServer& resourceServer,
    UpdateReporter* updateReporter,
    Spectre::Framework::ICancellationTokenPtr cancellationToken
) : FileParserBase(resourceServer, updateReporter),
    m_resourceServer(&resourceServer),
    m_cancellationToken(cancellationToken),
    m_asset3D(std::make_shared<Asset3D>()),
    m_currentGeometry(nullptr),
    m_hasSmoothingGroup(false),
    m_defaultMaterial(std::make_shared<MaterialDescriptor>()),
    m_author(unknownAuthor),
    m_yzflip(false),
    m_dataProcessed(false)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Spectre::Framework::MakeNullCancellationToken();
    }

    m_defaultMaterial->SetName("DefaultMaterial");

    m_currentMesh = m_asset3D->CreateMesh();

    m_commentChars = "#";
}

// Reads a line while ingoring \r and \n characters and returns number of bytes written to buffer
size_t GeometryParser::ReadLineWithoutEOL(TranscoderTextStream* stream, char* buffer, size_t maxLineSize)
{
    if (buffer == nullptr || maxLineSize < 1 || stream == nullptr ||  stream->EndOfStream())
    {
        return 0;
    }

    char* cur = buffer;
    size_t lMaxSize = maxLineSize - 1; // we need to stop 1 character before the size of the pBuffer since we need to add the \0

    while (size_t(cur - buffer) < lMaxSize )
    {
        char c;
        stream->Read(&c, 1);
        if (stream->CharactersRead() == 0 || (c == '\n'))
        {
            break;
        }

        // filter out consecutive end of line characters
        if (c == '\r')
        {
            uint64_t numRead = 0;
            char nextChar;
            do
            {
                stream->Read(&nextChar, 1);

                numRead = stream->CharactersRead();
                if (numRead == 0 )
                {
                    break;
                }

            } while (nextChar == '\r' || nextChar == '\n');

            // if we find a non carriage return or line feed reset the current position back one
            if (numRead > 0)
            {
                stream->Seek(-1, 1);
            }
            break;
        }
        else
        {
            *cur++ = c;
        }
    }

    *cur = '\0';
    return (cur - buffer);
}

// This version of Obj ReadLine appends lines with a backslash continuation tokens and replaces the token with a space.
size_t GeometryParser::ReadLine(TranscoderTextStream* stream, char* outputBuffer, size_t maxLineSize)
{
    if (stream == nullptr || stream->EndOfStream())
    {
        return 0;
    }

    size_t numRead = 0;
    size_t newlineNumRead = 0;
    size_t lastChar = numRead - 1;
    bool tokenFound = false;

    do
    {
        newlineNumRead = ReadLineWithoutEOL(stream, &outputBuffer[numRead], maxLineSize - numRead);
        numRead += newlineNumRead;
        if(numRead == 0)
        {
            break;
        }

        lastChar = numRead - 1; //ignore terminating '\0'

        //replace backslash
        tokenFound = false;
        if (outputBuffer[lastChar] == '\\')
        {
            outputBuffer[lastChar] = ' ';
            tokenFound = true;
        }
     } while (newlineNumRead > 0 && tokenFound);

     return numRead;
}

void GeometryParser::ProcessNonEmptyLine(LineTokensPtr& tokens)
{
    auto lineType = m_lineTypeTranslator.LookUp(tokens->at(0));

    bool didProcess = true;

    switch (lineType)
    {
    case v:
        ProcessVertex(tokens);
        break;
    case vt:
        ProcessTextureVertex(tokens);
        break;
    case vn:
        ProcessNormal(tokens);
        break;
    case f:
        ProcessFace(tokens);
        break;
    case SmoothingGroupLine:
        ProcessSmoothingGroup(tokens);
        break;
    case mtllib:
        ProcessMaterialLibrary(tokens);
        break;
    case usemtl:
        ProcessMaterial(tokens);
        break;
    case comment:
        ProcessComment(tokens);
        break;
    default:
        didProcess = false;
        break;
    }

    m_dataProcessed |= didProcess;
    m_cancellationToken->CheckCancelledAndThrow();
}

void GeometryParser::SetAuthorSettings(AuthorType author)
{
    switch (author)
    {
    case autodesk123D:
    {
        m_yzflip = true;
        break;
    }
    default:
    {
        // Do nothing
        break;
    }
    }
}

void GeometryParser::FinalizeParseStream(void)
{
    // Fail if no tokens were processed
    if (!m_dataProcessed)
    {
        throw TranscoderInvalidDataException("Obj file contains no data.");
    }
    // Only finalize geometry if we have data after running through the parsing process
    if (m_currentGeometry != nullptr)
    {
        FinalizeGeometry();
    }
}

void GeometryParser::ProcessVertex(LineTokensPtr& tokens)
{
    SpectreAssert(tokens->size() >= 1);
    Vector3 v = TokenParser::GetVector3AtPositionWithZeroPadding(tokens, 1);
    if (m_yzflip)
    {
        m_positions.push_back(FlipYZ(v));
    } else
    {
        m_positions.push_back(std::move(v));
    }
}

void GeometryParser::ProcessTextureVertex(LineTokensPtr& tokens)
{
    SpectreAssert(tokens->size() >= 1);
    Vector2 textureVertex = TokenParser::GetVector2AtPositionWithZeroPadding(tokens, 1);
    textureVertex.y = 1 - textureVertex.y;
    m_uv0s.push_back(textureVertex);
}

void GeometryParser::ProcessNormal(LineTokensPtr& tokens)
{
    SpectreAssert(tokens->size() >= 1);
    Vector3 v = m_tokenParser->GetVector3AtPosition(tokens, 1);

    // Wikipedia says "normals might not be unit vectors.", can't find any other information about this
    v.Normalize();

    if (m_yzflip)
    {
        m_normals.push_back(FlipYZ(v));
    }
    else
    {
        m_normals.push_back(std::move(v));
    }
}

void GeometryParser::ProcessFace(LineTokensPtr& tokens)
{
    if (!m_currentGeometry)
    {
        AddGeometry(m_defaultMaterial);
        TRACE_INFO(GeometryParser, "No 'newmtl' keyword found for the current face. Material set to default!")
    }

    size_t faceVertexCount = tokens->size() - 1;

    if (faceVertexCount < 3)
    {
        TRACE_WARN(GeometryParser, "Expected at least 3 verts for face (%d given)", int(faceVertexCount));
        return;
    }

    auto verticesDescription = tokens->data() + 1;

    std::vector<ObjVertex> vertices;
    vertices.reserve(faceVertexCount);

    for (size_t i = 0; i < faceVertexCount; i++)
    {
        auto vertexStr = verticesDescription[i];
        auto vertex = GetVertex(vertexStr);
        vertices.push_back(vertex);
    }

    auto triangleCount = faceVertexCount - 2;
    for (size_t i = 0; i < triangleCount; i++)
    {
        AddVertex(vertices[0]);
        AddVertex(vertices[i + 1]);
        AddVertex(vertices[i + 2]);
    }
}

void GeometryParser::AddVertex(const ObjVertex& vertex)
{
    auto position = GetElementFromObjStringIndex(m_positions, vertex.v);
    m_currentGeometry->AddPosition(std::move(position));

    if (!vertex.vt.empty())
    {
        auto uv0 = GetElementFromObjStringIndex(m_uv0s, vertex.vt);
        m_currentGeometry->AddUv0(std::move(uv0));
    }

    if (!vertex.vn.empty())
    {
        auto normal = GetElementFromObjStringIndex(m_normals, vertex.vn);
        m_currentGeometry->AddNormal(std::move(normal));
    }
    else if (m_hasSmoothingGroup)
    {
        m_currentGeometry->AddNormal(Vector3::Zero);
    }

    auto sizePositions = m_currentGeometry->GetPositions().size();
    auto sizeUv0s      = m_currentGeometry->GetUv0s().size();
    auto sizeNormals   = m_currentGeometry->GetNormals().size();

    if (sizeUv0s != 0 && sizeUv0s < sizePositions)
    {
        TRACE_WARN(GeometryParser, "Sparse uv0s detected, inserting padding element at index %zu", sizePositions);
        m_currentGeometry->AddUv0(Vector2(Vector2::Zero));
    }

    if (sizeNormals != 0 && sizeNormals < sizePositions)
    {
        TRACE_WARN(GeometryParser, "Sparse normals detected, inserting padding element at index %zu", sizePositions);
        m_currentGeometry->AddNormal(Vector3(Vector3::Zero));
    }
}

GeometryParser::ObjVertex GeometryParser::GetVertex(const std::string& vertexStr) const
{
    ObjVertex objVertex;

    auto split = Spectre::Utils::Split(vertexStr, kVertexDelimiter);
    if (split.size() > 0)
    {
        objVertex.v = split[0];
        if (split.size() > 1)
        {
            objVertex.vt = split[1];
            if (split.size() > 2)
            {
                objVertex.vn = split[2];
            }
        }
    }

    return objVertex;
}

void GeometryParser::ProcessSmoothingGroup(LineTokensPtr& tokens)
{
    // http://paulbourke.net/dataformats/obj/
    // Smoothing group statements let you identify elements over which
    // normals are to be interpolated to give those elements a smooth,
    // non - faceted appearance.This is a quick way to specify vertex
    // normals.

    if (tokens->size() < 2)
    {
        throw Spectre::Utils::SpectreException("Bad smoothing group. Expected a token after 's'.");
    }

    auto group = tokens->at(1);

    if (group == "off")
    {
        m_hasSmoothingGroup = false;
    }
    else
    {
        auto groupNumber = std::stol(group);
        m_hasSmoothingGroup = (groupNumber == 0) ? false : true;
    }
}

void GeometryParser::ProcessMaterialLibrary(LineTokensPtr& tokens)
{
    if (tokens->size() < 2)
    {
        // throw not supported
        return;
    }

    TRACE_VERBOSE(GeometryParser, "ProcessMaterialLibrary");

    std::string materialFile = "";

    for (size_t i = 1; i < tokens->size(); ++i)
    {
        size_t res = (*tokens)[i].find(".mtl");
        if (res == std::string::npos)
        {
            // material file names can have spaces :(
            // assume that any tokens without .mtl are part of the name; reaccumulate the tokens
            materialFile = materialFile + (*tokens)[i] + " ";
            continue;
        }
        else
        {
            materialFile += (*tokens)[i];
        }

        auto materialLibrary = RequestTextFileResource(materialFile);

        if (!materialLibrary)
        {
            TRACE_INFO(GeometryParser, "%s file not found. Skipping library", materialFile.c_str());
            return;
        }

        auto materialFileParser = std::make_unique<MaterialObjParser>(*m_resourceServer);
        materialFileParser->ParseStream(materialLibrary);
        m_materialLibraries.push_back(materialFileParser->GetMaterialLibrary());

        materialFile = ""; //reset
    }
}

std::shared_ptr<TranscoderTextStream> GeometryParser::RequestTextFileResource(std::string& fileName) const
{
    if (m_resourceServer)
    {
        return m_resourceServer->RequestTextFileResource(fileName);
    }
    return nullptr;
}

void GeometryParser::ProcessMaterial(LineTokensPtr& tokens)
{
    TRACE_VERBOSE(GeometryParser, "ProcessMaterial");

    std::shared_ptr<MaterialDescriptor> material;

    if (tokens->size() < 2)
    {
        // http://paulbourke.net/dataformats/obj/
        // "If a material name is not specified, a white material is used."
        // Spec says to use a white material, however we use a standard mid-grey for all Transcoders
        material = m_defaultMaterial;
    }
    else
    {
        material = FindMaterial((*tokens)[1]);
    }

    AddGeometry(material);
}

void GeometryParser::ProcessComment(LineTokensPtr& tokens)
{
    TRACE_VERBOSE(GeometryParser, "ProcessComment");

    if (tokens->size() > 1 &&
        m_author == unknownAuthor)
    {
        // only process comments when an author tag has yet to be discovered
        for (size_t i = 1; i < tokens->size(); ++i)
        {
            auto token = tokens->at(i);
            Spectre::Utils::TransformToLower(token);

            // Check for author markers
            auto authorType = m_authorTypeTranslator.LookUp(token);

            if (authorType != unknownAuthor)
            {
                TRACE_VERBOSE(GeometryParser, "Found Author tag: %s", token.c_str());
                m_author = authorType;
                SetAuthorSettings(m_author);
                break;
            }
        }
    }
}

std::shared_ptr<MaterialDescriptor> GeometryParser::FindMaterial(const std::string& name)
{
    for (auto materialLibrary : m_materialLibraries)
    {
        auto materialPtr = materialLibrary->find(name);
        if (materialPtr != materialLibrary->end())
        {
            return materialPtr->second;
        }
    }

    return m_defaultMaterial;
}

void GeometryParser::AddGeometry(std::shared_ptr<MaterialDescriptor> material)
{
    if (m_currentGeometry != nullptr)
    {
        FinalizeGeometry();
    }

    m_currentMesh->AddGeometry(material);
    m_currentGeometry = &m_currentMesh->GetGeometries().back();
}

void GeometryParser::FinalizeGeometry()
{
    if (m_currentGeometry->GetPositions().empty())
    {
        m_currentMesh->GetGeometries().pop_back();
        return;
    }

    if (m_hasSmoothingGroup)
    {
        // Generate smooth normals instead of placeholder Zero normals
        // https://computergraphics.stackexchange.com/questions/4031/programmatically-generating-vertex-normals
        // http://www.iquilezles.org/www/articles/normals/normals.htm

        // TODO: Multiple different smoothing groups for a single piece of geometry are currently not supported

        // Map of Position:Normal
        std::map<Vector3, Vector3> smoothedNormals;

        // For each Triangle
        const auto& positions = m_currentGeometry->GetPositions();
        for (size_t i = 0; i < positions.size(); i += 3)
        {
            auto& position0 = positions[i];
            auto& position1 = positions[i + 1];
            auto& position2 = positions[i + 2];

            auto u = position1 - position0;
            auto v = position2 - position0;
            auto normal = u.Cross(v);

            smoothedNormals[position0] += normal;
            smoothedNormals[position1] += normal;
            smoothedNormals[position2] += normal;
        }

        // Normalize all the generated normals
        for (auto& smoothedNormal : smoothedNormals)
        {
            smoothedNormal.second.Normalize();
        }

        // Copy normals so that we can update the missing ones
        auto normals = m_currentGeometry->GetNormals();
        if (normals.empty())
        {
            normals.resize(positions.size());
        }

        // For each position
        for (size_t i = 0; i < positions.size(); i++)
        {
            if (normals[i] == Vector3::Zero)
            {
                normals[i] = smoothedNormals.at(positions[i]);
            }
        }

        m_currentGeometry->SetNormals(std::move(normals));
    }
}
