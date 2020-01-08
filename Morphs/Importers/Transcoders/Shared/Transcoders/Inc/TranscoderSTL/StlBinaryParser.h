/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/IParser.h>

namespace Spectre
{
    namespace Transcoder
    {
        class Asset3D;
        class UpdateReporter;

        typedef std::function<void(float percentage)> PercentageCompleteCallback;

        class StlBinaryParser : public IParser
        {
        public:
            StlBinaryParser(IResourceServer& resourceServer, UpdateReporter* updateReporter, Framework::ICancellationTokenPtr cancellationToken = nullptr);
            ~StlBinaryParser();

            std::shared_ptr<Asset3D> ParseStream(std::shared_ptr<std::istream> stream);

        protected:
            static inline Spectre::Utils::Math::Vector3 FlipYZAxis(Spectre::Utils::Math::Vector3 position);
        private:
            Geometry ReadGeometry(std::shared_ptr<std::istream> stream, uint32_t triangleCount);

            UpdateReporter* m_updateReporter;
            Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}

inline Spectre::Utils::Math::Vector3 Spectre::Transcoder::StlBinaryParser::FlipYZAxis(
    Spectre::Utils::Math::Vector3 position)
{
    return Spectre::Utils::Math::Vector3(position.x, position.z, -position.y);
}
