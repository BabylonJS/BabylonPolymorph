/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <Framework/GeometryUtils.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <TranscoderSTL/StlAsciiParser.h>

#pragma strict_gs_check(on)
#pragma pack(2)

DEFINE_TRACE_AREA(StlAsciiParser, 0);

using namespace Babylon::Transcoder;

namespace
{
    Babylon::Transcoder::LineTypeTranslator<StlAsciiParser::LineType> GeometryLineTypeTranslator()
    {
        auto sharedMap = std::map<std::string, StlAsciiParser::LineType>();
        sharedMap["solid"]    = StlAsciiParser::LineType::Solid;
        sharedMap["facet"]    = StlAsciiParser::LineType::Facet;
        sharedMap["outer"]    = StlAsciiParser::LineType::OuterLoop;
        sharedMap["vertex"]   = StlAsciiParser::LineType::Vertex;
        sharedMap["endloop"]  = StlAsciiParser::LineType::EndLoop;
        sharedMap["endfacet"] = StlAsciiParser::LineType::EndFacet;
        sharedMap["endsolid"] = StlAsciiParser::LineType::EndSolid;
        return LineTypeTranslator<StlAsciiParser::LineType>(sharedMap);
    }
}

const LineTypeTranslator<StlAsciiParser::LineType> Babylon::Transcoder::StlAsciiParser::m_lineTypeTranslator = GeometryLineTypeTranslator();

StlAsciiParser::StlAsciiParser(IResourceServer& resourceServer, UpdateReporter* updateReporter, Babylon::Framework::ICancellationTokenPtr cancellationToken)
    : FileParserBase(resourceServer, updateReporter),
    m_asset3D(std::make_shared<Asset3D>()),
    m_cancellationToken(cancellationToken)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }
}

// Hierarchy of ASCII STL file is as follows:
// 
// solid [name]
//   facet [normal n.x n.y n.z]
//     outer loop
//       vertex v.x v.y v.z
//       vertex v.x v.y v.z
//       vertex v.x v.y v.z
//     endloop
//   endfacet
// endsolid [name]
void StlAsciiParser::ProcessNonEmptyLine(Babylon::Transcoder::LineTokensPtr& tokens)
{
    m_cancellationToken->CheckCancelledAndThrow();

    auto lineType = m_lineTypeTranslator.LookUp(tokens->at(0));

    switch (lineType)
    {
    case StlAsciiParser::LineType::Solid:
        ParseSolid(tokens);
        break;

    case StlAsciiParser::LineType::Facet:
        ParseFacet(tokens);
        break;

    case StlAsciiParser::LineType::OuterLoop:
        ParseOuterLoop(tokens);
        break;

    case StlAsciiParser::LineType::Vertex:
        ParseVertex(tokens);
        break;

    case StlAsciiParser::LineType::EndLoop:
        ParseEndLoop(tokens);
        break;

    case StlAsciiParser::LineType::EndFacet:
        CheckAndPop(LineType::Facet, "Expected 'endfacet' element at the same level as 'facet' element.", tokens);
        break;

    case StlAsciiParser::LineType::EndSolid:
        CheckAndPop(LineType::Solid, "Expected 'endfacet' element at the same level as 'facet' element.", tokens);
        break;

    default:
        throw Babylon::Utils::BabylonException("Unexpected element type: " + tokens->at(0));
    }
}

void StlAsciiParser::CheckAndPush(LineType current, LineType parent, const std::string& message)
{
    if (m_hierarchy.empty() || m_hierarchy.top() != parent)
    {
        throw Babylon::Utils::BabylonException(message);
    }

    m_hierarchy.push(current);
}

void StlAsciiParser::CheckAndPop(LineType sibling, const std::string& message, const Babylon::Transcoder::LineTokensPtr& tokens)
{
    if (m_hierarchy.top() != sibling)
    {
        throw Babylon::Utils::BabylonException(message);
    }

    if (tokens->size() > 1)
    {
        TRACE_WARN(StlAsciiParser, "Unexpected number of tokens for '%s' element: %zu", tokens->at(0).c_str(), tokens->size());
    }

    m_hierarchy.pop();
}

void StlAsciiParser::ParseSolid(const Babylon::Transcoder::LineTokensPtr& tokens)
{
    if (tokens->size() == 2)
    {
        m_asset3D->SetName(tokens->at(1));
    }

    if (!m_hierarchy.empty())
    {
        throw Babylon::Utils::BabylonException("Unexpected 'solid' element found inside another element.");
    }

    m_hierarchy.push(LineType::Solid);
}

void StlAsciiParser::ParseFacet(const Babylon::Transcoder::LineTokensPtr& tokens)
{
    CheckAndPush(LineType::Facet, LineType::Solid, "Expected 'facet' element to be directly under 'solid' element.");

    if (tokens->size() != 1 && tokens->size() != 5)
    {
        TRACE_WARN(StlAsciiParser, "Unexpected number of tokens for 'facet' element: %zu", tokens->size());
    }

    // https://www.fabbers.com/tech/STL_Format
    // Facet orientation. The facets define the surface of a 3-dimensional object. As such, each facet is part of
    // the boundary between the interior and the exterior of the object. The orientation of the facets (which way
    // is "out" and which way is "in") is specified redundantly in two ways which must be consistent. First, the
    // direction of the normal is outward. Second, the vertices are listed in counterclockwise order when looking
    // at the object from the outside (right-hand rule).

    // For two reasons, therefore, we ignore the Facet normal:
    //    a) The normal could have been calculated wrong, e.g. by an old version of Transcoders
    //    b) The implicit normal should be the same as the explicit normal
}

void StlAsciiParser::ParseOuterLoop(const Babylon::Transcoder::LineTokensPtr& tokens)
{
    CheckAndPush(LineType::OuterLoop, LineType::Facet, "Expected 'outer loop' element to be directly under 'facet' element.");

    if (tokens->size() != 2)
    {
        TRACE_WARN(StlAsciiParser, "Unexpected number of tokens for 'facet' element: %zu", tokens->size());
    }

    if (tokens->at(1) != "loop")
    {
        throw Babylon::Utils::BabylonException("Expected 'loop' after 'outer' element.");
    }
}

void StlAsciiParser::ParseVertex(const Babylon::Transcoder::LineTokensPtr& tokens)
{
    if (tokens->size() != 4)
    {
        throw Babylon::Utils::BabylonException("Unexpected number of tokens for 'vertex' element: %zu", tokens->size());
    }

    if (m_hierarchy.top() != LineType::OuterLoop)
    {
        throw Babylon::Utils::BabylonException("Expected 'vertex' element to be inside 'outer loop' element.");
    }

    Vector3 position;
    position.x = static_cast<float>(atof(tokens->at(1).c_str()));
    position.y = static_cast<float>(atof(tokens->at(3).c_str()));
    position.z = static_cast<float>(-atof(tokens->at(2).c_str()));

    m_positions.push_back(position);
}

void StlAsciiParser::ParseEndLoop(const Babylon::Transcoder::LineTokensPtr& tokens)
{
    CheckAndPop(LineType::OuterLoop, "Expected 'endloop' element at the same level as 'loop' element.", tokens);

    if (m_positions.size() % 3 != 0)
    {
        throw Babylon::Utils::BabylonException("Expected multiple of 3 vertices.");
    }
}

void StlAsciiParser::FinalizeParseStream()
{
    if (!m_hierarchy.empty())
    {
        throw Babylon::Utils::BabylonException("Unexpected end of file.");
    }

    Geometry geometry(std::make_shared<MaterialDescriptor>());
    geometry.SetIndices(m_indices);
    geometry.SetPositions(m_positions);

    m_asset3D->SetMesh(std::make_shared<Mesh>(std::move(geometry)));
}
