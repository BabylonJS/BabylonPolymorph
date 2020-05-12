/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "PluginSDKPch.h"

#include <algorithm>
#include <cstdlib>
#include <PluginSDK/TokenParser.h>
#include <Framework/GeometryUtils.h>
#include <CoreUtils/StringUtils.h>

using namespace Babylon::Transcoder;

TokenParser::~TokenParser()
{
}

float TokenParser::GetFloatAtPosition(LineTokensPtr const& tokens, size_t position)
{
    AssertTokensNumber(tokens, position);

    return static_cast<float>(std::atof((*tokens)[position].c_str()));
}

unsigned int TokenParser::GetUnsignedIntAtPosition(LineTokensPtr const& tokens, size_t position)
{
    AssertTokensNumber(tokens, position);

    return static_cast<unsigned int>(std::atoi((*tokens)[position].c_str()));
}

DXSM::Vector3 TokenParser::GetVector3AtPosition(LineTokensPtr const& tokens, size_t position)
{
    AssertTokensNumber(tokens, position + 2);

    auto ret = DXSM::Vector3();
    ret.x = static_cast<float>(std::atof((*tokens)[position].c_str()));
    ret.y = static_cast<float>(std::atof((*tokens)[position + 1].c_str()));
    ret.z = static_cast<float>(std::atof((*tokens)[position + 2].c_str()));

    return ret;
}

DXSM::Vector2 TokenParser::GetVector2AtPosition(LineTokensPtr const& tokens, size_t position)
{
    AssertTokensNumber(tokens, position + 1);

    auto ret = DXSM::Vector2();
    ret.x = static_cast<float>(std::atof((*tokens)[position].c_str()));
    ret.y = static_cast<float>(std::atof((*tokens)[position + 1].c_str()));

    return ret;
}

DXSM::Vector3 TokenParser::GetVector3AtPositionWithZeroPadding(LineTokensPtr const& tokens, size_t position)
{
    size_t tokensSize = tokens->size();

    DXSM::Vector3 ret(0.0f, 0.0f, 0.0f);
    for (size_t i = 0; i < 3 && i+position < tokensSize; i++)
    {
        (&ret.x)[i] = static_cast<float>(std::atof((*tokens)[i + position].c_str()));
    }

    return ret;
}

DXSM::Vector2 TokenParser::GetVector2AtPositionWithZeroPadding(LineTokensPtr const& tokens, size_t position)
{
    size_t tokensSize = tokens->size();

    DXSM::Vector2 ret(0.0f, 0.0f);
    for (size_t i = 0; i < 2 && i+position < tokensSize; i++)
    {
        (&ret.x)[i] = static_cast<float>(std::atof((*tokens)[i+position].c_str()));
    }

    return ret;
}

char TokenParser::GetCharAtPosition(LineTokensPtr const& tokens, size_t position)
{
    AssertTokensNumber(tokens, position);
    return (*tokens)[position][0];
}

bool TokenParser::GetBoolAtPosition(LineTokensPtr const& tokens, size_t position)
{
    AssertTokensNumber(tokens, position);
    auto value = (*tokens)[position];

    Babylon::Utils::TransformToLower(value);

    if (value == "on")
    {
        return true;
    }

    if (value == "off")
    {
        return false;
    }

    throw Babylon::Utils::BabylonException("The boolean token was not recognised");
}

void TokenParser::AssertTokensNumber(LineTokensPtr const& tokens, size_t expectedNumberOfTokens)
{
    if (tokens->size() > expectedNumberOfTokens)
    {
        return;
    }

    throw Babylon::Utils::BabylonException("The number of tokens is smaller than the expected.");
}
