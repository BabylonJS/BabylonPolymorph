/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"
#include <Transcoders.h>
#include "TranscodersTelemetryHelper.h"
#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/TelemetryTraceLoggerFactory.h>
#include <Asset3D/Asset3D.h>
#include <CoreUtils/Gltf.h>

#include <algorithm>

namespace Spectre
{
    namespace Transcoder
    {
        namespace
        {
            void SetTelemetryAnimationTypes(Spectre::Utils::TelemetryTraceLogger::AnimationStats& animStats, Spectre::Utils::glTF::AnimationMetadata::eType animationTypes)
            {
                unsigned int animationType = static_cast<unsigned int>(animationTypes);
                if (animationType & static_cast<unsigned int>(Spectre::Utils::glTF::AnimationMetadata::eType::kMorph))
                {
                    animStats.MarkAnimationType(Spectre::Utils::TelemetryTraceLogger::AnimationStats::AnimationType::Morph);
                }
                if (animationType & static_cast<unsigned int>(Spectre::Utils::glTF::AnimationMetadata::eType::kNode))
                {
                    animStats.MarkAnimationType(Spectre::Utils::TelemetryTraceLogger::AnimationStats::AnimationType::Node);
                }
                if (animationType & static_cast<unsigned int>(Spectre::Utils::glTF::AnimationMetadata::eType::kSkinned))
                {
                    animStats.MarkAnimationType(Spectre::Utils::TelemetryTraceLogger::AnimationStats::AnimationType::Skeletal);
                }
            }

            void GetAnimationStats(Spectre::Utils::TelemetryTraceLogger::AnimationStats& animStats, const Asset3DPtr& asset3D)
            {
                const auto& channelAnimations = asset3D->GetChannelAnimations();
                const auto& skins = asset3D->GetSkins();

                if (channelAnimations || skins)
                {
                    SpectreAssert(asset3D->GetSkeletons().empty());
                    SpectreAssert(asset3D->GetAnimations().empty());

                    animStats.m_numAnimations = static_cast<unsigned int>(channelAnimations->GetAnimationCount());

                    std::set<std::string> allSkinJoints;
                    for (size_t skinIndex = 0; skinIndex < skins->GetSkinCount(); skinIndex++)
                    {
                        auto& skinJoints = skins->GetSkinJoints(skinIndex);
                        allSkinJoints.insert(skinJoints.begin(), skinJoints.end());
                    }

                    std::for_each(allSkinJoints.begin(), allSkinJoints.end(), [&animStats](const std::string& skinJointId) { animStats.m_boneIds.insert(std::strtoull(skinJointId.c_str(), nullptr, 10)); });

                    for (size_t animationIndex = 0; animationIndex < channelAnimations->GetAnimationCount(); animationIndex++)
                    {
                        const auto animationId = channelAnimations->GetAnimationId(animationIndex);
                        const auto animationDuration = channelAnimations->GetAnimationTime(animationId);
                        animStats.m_totalAnimationDuration += animationDuration.second - animationDuration.first;
                        SetTelemetryAnimationTypes(animStats, channelAnimations->GetAnimationTypes(animationId, allSkinJoints));
                    }
                }
                else
                {
                    const auto& legacyAnimations = asset3D->GetAnimations();
                    const auto& legacySkeletons = asset3D->GetSkeletons();

                    for (const auto& skel : legacySkeletons)
                    {
                        for (const auto& joint : skel.m_joints)
                        {
                            animStats.m_boneIds.insert(joint.m_sceneNodeId);
                        }
                        if (!skel.m_joints.empty())
                        {
                            animStats.MarkAnimationType(Spectre::Utils::TelemetryTraceLogger::AnimationStats::AnimationType::Skeletal);
                        }
                    }

                    animStats.m_numAnimations = static_cast<unsigned int>(legacyAnimations.size());

                    for (const auto& anims : legacyAnimations)
                    {
                        animStats.m_totalAnimationDuration += static_cast<float>(anims.m_timeSpan.second - anims.m_timeSpan.first);
                    }
                }
            }
        }

        TranscodersTelemetryHelper::TranscodersTelemetryHelper(
                const std::string originalExtensionType,
                const std::string destinationExtensionType,
                const std::string transcoderVersion,
                bool enabled)
            : m_telemetryLogger(nullptr),
            m_transcodeOptions(),
            m_telemetryEnabled(enabled),  // disable telemetry by default
            m_exceptionDetails(""),
            m_originalExtensionType(originalExtensionType),
            m_destinationExtensionType(destinationExtensionType),
            m_transcoderVersion(transcoderVersion),
            m_importActivityID(Utils::TelemetryTraceUid::Zero),
            m_exportActivityID(Utils::TelemetryTraceUid::Zero),
            m_transcoderInitializedTime(std::chrono::time_point<std::chrono::steady_clock>()),
            m_transcodeStartTime(std::chrono::time_point<std::chrono::steady_clock>())
        {
        }

        TranscodersTelemetryHelper::~TranscodersTelemetryHelper()
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            int timeSinceInitialization = CalculateElapsedTime(m_transcoderInitializedTime);
            SendTranscoderDestroyed(timeSinceInitialization, m_exceptionDetails.c_str());
        }

        void TranscodersTelemetryHelper::Initialize(const std::unordered_map<std::string, std::string>& transcodeOptions, Spectre::Utils::TelemetryTraceLoggerFactoryFunctionType factory)
        {
            m_transcodeOptions = transcodeOptions;

            if (!m_telemetryEnabled)
            {
                return;
            }

            if (factory == nullptr)
            {
                factory = Spectre::Utils::CreateTelemetryTraceLogger;
            }

            m_telemetryLogger = factory();
            m_telemetryLogger->SetCorrelationVectorGUID(Utils::TelemetryTraceLoggerCorrelationVectorId());

            m_transcoderInitializedTime = std::chrono::steady_clock::now();

            // Send successful transcoder initialization event
            SendTranscoderInitialization();
        }

        void TranscodersTelemetryHelper::SendImportStartTelemetry()
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            m_importActivityID = Utils::TelemetryTraceUid::CreateUid();

            auto importOptionsString = GetTranscodeOptionsStringForTelemetry();
            m_transcodeStartTime = std::chrono::steady_clock::now();

            // Send Import Start event
            m_telemetryLogger->Import3DModelStart(
                m_importActivityID,
                m_originalExtensionType.c_str(),
                m_destinationExtensionType.c_str(),
                importOptionsString.c_str(),
                m_transcoderVersion.c_str());
        }

        void TranscodersTelemetryHelper::SendImportCompleteTelemetry(const std::shared_ptr<Spectre::Transcoder::Asset3D> asset3DFromImport, const uint64_t streamByteSize)
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            auto vertexCount = asset3DFromImport.get()->GetVertexCount();
            auto indexCount = asset3DFromImport.get()->GetIndexCount();
            auto textureCount = asset3DFromImport.get()->GetTextureCount();
            auto vertexBufferMemory = asset3DFromImport.get()->GetVertexBufferMemory();
            auto indexBufferMemory = asset3DFromImport.get()->GetIndexBufferMemory();
            auto textureMemory = asset3DFromImport.get()->GetTextureMemory();

            // Caller should already have called SendImportStartTelemetry. If they haven't,
            // m_transcodeStartTime will not be set;  use m_transcoderInitializedTime instead
            int importDuration = m_transcodeStartTime != std::chrono::time_point<std::chrono::steady_clock>()
                ? CalculateElapsedTime(m_transcodeStartTime) : CalculateElapsedTime(m_transcoderInitializedTime);

            uint32_t sizeInKB = static_cast<unsigned int> (streamByteSize / 1024ULL);

            GetAnimationStats(m_animStats, asset3DFromImport);

            // Send Import End event
            // Exceptions will cause Import3DModelAbort to be sent instead of End,
            // so no need for exception info
            m_telemetryLogger->Import3DModelEnd(
                m_importActivityID,
                true,
                "",
                importDuration,
                m_originalExtensionType.c_str(),
                m_destinationExtensionType.c_str(),
                vertexCount,
                indexCount,
                textureCount,
                static_cast<int64_t>(vertexBufferMemory),
                static_cast<int64_t>(indexBufferMemory),
                textureMemory,
                m_animStats.m_numAnimations,
                static_cast<unsigned int>(m_animStats.m_boneIds.size()),
                static_cast<unsigned int>(m_animStats.m_animationTypes.to_ulong()),
                m_animStats.m_totalAnimationDuration,
                sizeInKB,
                m_transcoderVersion.c_str()
            );
        }

        void TranscodersTelemetryHelper::SendImportAbortTelemetry(const std::string exceptionDetails, const uint64_t streamByteSize)
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            m_exceptionDetails = exceptionDetails;
            uint32_t sizeInKB = static_cast<unsigned int> (streamByteSize / 1024ULL);

            // Send Import Abort event
            m_telemetryLogger->Import3DModelAbort(m_importActivityID, m_exceptionDetails.c_str(), sizeInKB, m_transcoderVersion.c_str());
        }

        void TranscodersTelemetryHelper::SendExportStartTelemetry()
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            m_exportActivityID = Utils::TelemetryTraceUid::CreateUid();

            m_transcodeStartTime = std::chrono::steady_clock::now();

            // Send Export Start event
            m_telemetryLogger->Export3DModelStart(
                m_exportActivityID,
                m_importActivityID,
                m_originalExtensionType.c_str(),
                m_destinationExtensionType.c_str(),
                m_transcoderVersion.c_str()
            );
        }

        void TranscodersTelemetryHelper::SendExportCompleteTelemetry(const std::shared_ptr<Spectre::Transcoder::Asset3D> asset3DFromImport)
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            auto vertexCount = asset3DFromImport.get()->GetVertexCount();
            auto indexCount = asset3DFromImport.get()->GetIndexCount();
            auto textureCount = asset3DFromImport.get()->GetTextureCount();
            auto vertexBufferMemory = asset3DFromImport.get()->GetVertexBufferMemory();
            auto indexBufferMemory = asset3DFromImport.get()->GetIndexBufferMemory();
            auto textureMemory = asset3DFromImport.get()->GetTextureMemory();

            // Caller should already have called SendExportStartTelemetry. If they haven't,
            // m_transcodeStartTime will not be set;  use m_transcoderInitializedTime instead
            int exportDuration = m_transcodeStartTime != std::chrono::time_point<std::chrono::steady_clock>()
                ? CalculateElapsedTime(m_transcodeStartTime) : CalculateElapsedTime(m_transcoderInitializedTime);

            GetAnimationStats(m_animStats, asset3DFromImport);

            // Send Export End event
            // Exceptions will cause Export3DModelAbort to be sent instead of End
            // so here set success=true and no exception info
            m_telemetryLogger->Export3DModelEnd(
                m_exportActivityID,
                m_importActivityID,
                true,
                "",
                exportDuration,
                m_originalExtensionType.c_str(),
                m_destinationExtensionType.c_str(),
                vertexCount,
                indexCount,
                textureCount,
                vertexBufferMemory,
                indexBufferMemory,
                textureMemory,
                m_animStats.m_numAnimations,
                static_cast<unsigned int>(m_animStats.m_boneIds.size()),
                static_cast<unsigned int>(m_animStats.m_animationTypes.to_ulong()),
                m_animStats.m_totalAnimationDuration,
                m_transcoderVersion.c_str()
            );
        }

        void TranscodersTelemetryHelper::SendExportAbortTelemetry(const std::string exceptionDetails)
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            m_exceptionDetails = exceptionDetails;

            // Send Export Abort event
            m_telemetryLogger->Export3DModelAbort(m_exportActivityID, m_importActivityID, m_exceptionDetails.c_str(), m_transcoderVersion.c_str());
        }

        void TranscodersTelemetryHelper::SendTranscoderInitialization()
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            // Send successful Transcoder Initialized event
            // TODO: TEMP COMMENT
            //m_telemetryLogger->TranscoderInitialization(true, "", Spectre::Transcoder::GetVersionString(), m_transcoderVersion.c_str());
        }

        void TranscodersTelemetryHelper::SendTranscoderDestroyed(const int timeSinceInitialization, const char* exceptionDetails)
        {
            if (!m_telemetryEnabled)
            {
                return;
            }

            // Send Transcoder Destroyed event
            m_telemetryLogger->TranscoderDestroyed(timeSinceInitialization, exceptionDetails, m_transcoderVersion.c_str());
        }

        std::string TranscodersTelemetryHelper::GetTranscodeOptionsStringForTelemetry() const
        {
            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            writer.StartObject();

            for (const auto& option : m_transcodeOptions)
            {
                writer.Key(option.first.c_str());
                writer.String(option.second.c_str());
            }

            writer.EndObject();
            return buffer.GetString();
        }

        int TranscodersTelemetryHelper::CalculateElapsedTime(const std::chrono::time_point<std::chrono::steady_clock> startTime)
        {
            auto endTime = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> elapsedTranscodeTime = endTime - startTime;
            return (int)(elapsedTranscodeTime.count());
        }
    }
}