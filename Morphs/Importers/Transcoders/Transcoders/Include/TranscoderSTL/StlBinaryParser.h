/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/IParser.h>

namespace Babylon
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
            static inline Babylon::Utils::Math::Vector3 FlipYZAxis(Babylon::Utils::Math::Vector3 position);
        private:
            Geometry ReadGeometry(std::shared_ptr<std::istream> stream, uint32_t triangleCount);

            UpdateReporter* m_updateReporter;
            Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}

inline Babylon::Utils::Math::Vector3 Babylon::Transcoder::StlBinaryParser::FlipYZAxis(
    Babylon::Utils::Math::Vector3 position)
{
    return Babylon::Utils::Math::Vector3(position.x, position.z, -position.y);
}
