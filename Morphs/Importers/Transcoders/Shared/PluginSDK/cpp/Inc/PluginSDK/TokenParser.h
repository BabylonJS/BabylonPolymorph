/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <PluginSDK/LineTokensPtr.h>

namespace Spectre {
    // Forward declaration of Vector3, Vector2
    namespace Utils
    {
        namespace Math
        {
            struct Vector3;
            struct Vector2;
        }
    }

    namespace Transcoder {

        namespace DXSM = Spectre::Utils::Math;

        class TokenParser
        {
        public:
            virtual ~TokenParser();
            static float GetFloatAtPosition(LineTokensPtr const& tokens, size_t position);
            static unsigned int GetUnsignedIntAtPosition(LineTokensPtr const& tokens, size_t position);
            static DXSM::Vector3 GetVector3AtPosition(LineTokensPtr const& tokens, size_t position);
            static DXSM::Vector2 GetVector2AtPosition(LineTokensPtr const& tokens, size_t position);
            static DXSM::Vector3 GetVector3AtPositionWithZeroPadding(LineTokensPtr const& tokens, size_t position);
            static DXSM::Vector2 GetVector2AtPositionWithZeroPadding(LineTokensPtr const& tokens, size_t position);
            static char GetCharAtPosition(LineTokensPtr const& tokens, size_t position);
            static bool GetBoolAtPosition(LineTokensPtr const& tokens, size_t position);

        protected:
            static void AssertTokensNumber(LineTokensPtr const& tokens, size_t expectedNumberOfTokens);
        };
    }
}
