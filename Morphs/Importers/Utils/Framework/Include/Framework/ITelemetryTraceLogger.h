/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <bitset>
#include <set>
#include <string>
#include <map>

#include <CoreUtils/Assert.h>
#include <CoreUtils/Enum.h>
#include <CoreUtils/Pimpl.h>
#include <CoreUtils/Trace.h>
#include <Framework/Types.h>

namespace Babylon
{
    namespace Utils
    {
#ifdef _WIN32
        typedef GUID TelemetryTraceLoggerCorrelationVectorId;
#else
        typedef uint32_t TelemetryTraceLoggerCorrelationVectorId;
#endif

        class TelemetryTraceUid final
        {
        public:
            static TelemetryTraceUid CreateUid();

            TelemetryTraceUid(TelemetryTraceUid&& other);
            TelemetryTraceUid(const TelemetryTraceUid& other);
            ~TelemetryTraceUid();

            bool IsZero() const;

            const char* GetUIDAsString() const;

            TelemetryTraceUid& operator=(TelemetryTraceUid&& other);
            TelemetryTraceUid& operator=(const TelemetryTraceUid& other);

            static const TelemetryTraceUid Zero;

            // Impl
            class Impl;
            Pimpl<Impl> m_impl;
        private:
            TelemetryTraceUid();
            TelemetryTraceUid(Impl&& impl);
        };

        namespace TelemetryTraceLogger
        {
            struct AnimationStats
            {
                enum class AnimationType : unsigned int
                {
                    // Start at 0 so as to not waste bits
                    Skeletal = 0,
                    Node,
                    Morph,

                    COUNT,
                    None = COUNT
                };

                unsigned int                                m_numAnimations;
                std::set<uint64_t>                          m_boneIds;
                // Bitmask for animation types present in file
                // Must match AnimationStats::AnimationType (above)

                // Bit 0 - Skeletal animations present
                // Bit 1 - Node animations present
                // Bit 2 - Morph animations present
                // ...
                // TODO: Update this when new animation types are introduced/supported
                std::bitset<8>                              m_animationTypes;
                float                                       m_totalAnimationDuration;   // in seconds

                AnimationStats()
                    : m_numAnimations(0)
                    , m_boneIds()
                    , m_animationTypes()
                    , m_totalAnimationDuration(0.f)
                {}

                AnimationStats& operator+=(const AnimationStats& rhs)
                {
                    m_numAnimations += rhs.m_numAnimations;
                    m_boneIds.insert(rhs.m_boneIds.begin(), rhs.m_boneIds.end());
                    m_animationTypes |= rhs.m_animationTypes;
                    m_totalAnimationDuration += rhs.m_totalAnimationDuration;

                    return *this;
                }

                void Clear()
                {
                    m_numAnimations = 0;
                    m_boneIds.clear();
                    m_animationTypes.reset();
                    m_totalAnimationDuration = 0.f;
                }

                void MarkAnimationType(AnimationType type)
                {
                    if (type == AnimationType::None)
                    {
                        m_animationTypes.reset();
                        return;
                    }

                    m_animationTypes.set(Babylon::Utils::underlying_cast(type));
                }
            };

            struct LoaderStats
            {
                LoaderStats() :
                    m_nodeCount(0),
                    m_meshInstanceCount(0),
                    m_meshCount(0),
                    m_materialCount(0),
                    m_indexCount(0),
                    m_vertexCount(0),
                    m_textureCount(0),
                    m_indexDataSize(0),
                    m_vertexDataSize(0),
                    m_textureDataSize(0)
                {}

                uint32_t m_nodeCount;
                uint32_t m_meshInstanceCount;

                uint32_t m_meshCount;
                uint32_t m_materialCount;

                uint64_t m_indexCount;
                uint64_t m_vertexCount;
                uint64_t m_textureCount;

                uint64_t m_indexDataSize;
                uint64_t m_vertexDataSize;
                uint64_t m_textureDataSize;
            };


            // Base struct for Engine profile data
            struct ProfileDataBase
            {
                float m_maxTime = std::numeric_limits<float>::lowest();
                float m_minTime = std::numeric_limits<float>::max();
                float m_summedTime = 0.f;
                size_t m_numDataPoints = 0;

                // Name to identify this data
                std::wstring m_uniqueName = L"";

                std::wstring GetName()
                {
                    return m_uniqueName;
                }

                void SetName(const std::wstring& name)
                {
                    m_uniqueName = name;
                }

                void AddDataPoint(float timeval)
                {
                    if (timeval > 0.f)
                    {
                        m_maxTime = std::max(m_maxTime, timeval);
                        m_minTime = std::min(m_minTime, timeval);

                        m_summedTime += timeval;
                        ++m_numDataPoints;
                    }
                }

                void Clear()
                {
                    m_maxTime = std::numeric_limits<float>::lowest();
                    m_minTime = std::numeric_limits<float>::max();
                    m_summedTime = 0.f;
                    m_numDataPoints = 0;
                }

                inline float GetAverage() const
                {
                    return(m_numDataPoints ? (m_summedTime / m_numDataPoints) : 0.f);
                }
            };

            struct CpuProfileData
            {
                ProfileDataBase m_data;
            };

            struct GpuProfileData
            {
                // Each entry represents the data for one GPU.
                // The key is a generic pointer-cast-to-int type.
                // While it is derived from a pointer, don't use it as one.
                std::map<std::uintptr_t, ProfileDataBase>  m_dataList;
                // Last recorded frame, per device
                std::map<std::uintptr_t, uint64_t>         m_lastFrame;

                void Clear()
                {
                    for (auto& entry : m_dataList)
                    {
                        entry.second.Clear();
                    }
                }
            };
        }

        struct TelemTraceLoggerAttributes
        {
            TelemTraceLoggerAttributes(TelemetryTraceUid& canvasActivityId, TelemetryTraceUid& transcoderActivityId, std::string& arch) :
                m_canvasActivityIdRef(canvasActivityId),
                m_transcoderActivityIdRef(transcoderActivityId),
                m_baseArchitectureRef(arch) {}

            TelemetryTraceUid& m_canvasActivityIdRef;
            TelemetryTraceUid& m_transcoderActivityIdRef;
            std::string& m_baseArchitectureRef;

        private:
            TelemTraceLoggerAttributes() = default;
        };

        class ITelemetryTraceLogger
        {
        public:

            ITelemetryTraceLogger() = default;
            virtual ~ITelemetryTraceLogger() = default;

            ITelemetryTraceLogger(ITelemetryTraceLogger && op) noexcept;              // movable and noncopyable
            ITelemetryTraceLogger& operator=(ITelemetryTraceLogger && op) noexcept;   //

            virtual const std::shared_ptr<TelemTraceLoggerAttributes> GetAttributes() = 0;

            virtual void SetCorrelationVectorGUID(TelemetryTraceLoggerCorrelationVectorId guid) = 0;

            virtual void CanvasInitialization(bool success, const char* exceptionDetails, const char* packageVersion) = 0;

            virtual void CanvasDestroyed(int durationMS, const char* exceptionDetails) = 0;

            virtual void CanvasSuspended(int durationMS, const char* exceptionDetails) = 0;

            virtual void LoadModelSessionStart(const TelemetryTraceUid& loadActivityId, const char* modelExtension) = 0;

            virtual void LoadModelSessionEnd(const TelemetryTraceUid& loadActivityId,
                bool success,
                const char* exceptionDetails,
                std::chrono::milliseconds duration,
                const TelemetryTraceLogger::LoaderStats& loaderStats,
                const TelemetryTraceLogger::AnimationStats& animStats) = 0;

            virtual void LoadModelSessionAbort(
                const TelemetryTraceUid& loadActivityId,
                const char* exceptionDetails) = 0;

            virtual void SerializeModelSessionStart(
                const TelemetryTraceUid& serializeActivityId,
                const char* modelExtension) = 0;

            virtual void SerializeModelSessionEnd(
                const TelemetryTraceUid& serializeActivityId,
                bool success,
                const char* exceptionDetails,
                std::chrono::milliseconds duration,
                const TelemetryTraceLogger::AnimationStats& animStats) = 0;

            virtual void SerializeModelSessionAbort(
                const TelemetryTraceUid& serializeActivityId,
                const char* exceptionDetails) = 0;

            virtual void CanvasException(const char* exceptionDetails) = 0;

            virtual void TranscoderInitialization(
                bool success,
                const char* exceptionDetails,
                const char* packageVersion,
                const char* transcoderVersion) = 0;

            virtual void TranscoderDestroyed(
                int durationMS,
                const char* exceptionDetails,
                const char* transcoderVersion) = 0;

            virtual void Import3DModelStart(
                const TelemetryTraceUid&  importActivityID,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                const char* importOptions,
                const char* transcoderVersion) = 0;

            virtual void Import3DModelAbort(
                const TelemetryTraceUid&  importActivityID,
                const char* exceptionDetails,
                uint32_t sizeInKB,
                const char* transcoderVersion) = 0;

            virtual void Import3DModelEnd(
                const TelemetryTraceUid&  importActivityID,
                bool success,
                const char* exceptionDetails,
                int durationMS,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                size_t vertexCount,
                size_t indexCount,
                size_t textureCount,
                int64_t vertexBufferMemory,
                int64_t indexBufferMemory,
                int64_t textureMemory,
                unsigned int numAnimations,
                unsigned int numBones,
                unsigned int animationTypes,
                float totalAnimationDuration,
                uint32_t sizeInKB,
                const char* transcoderVersion) = 0;

            virtual void Export3DModelStart(
                const TelemetryTraceUid&  exportActivityID,
                const TelemetryTraceUid&  importActivityID,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                const char* transcoderVersion) = 0;

            virtual void Export3DModelAbort(
                const TelemetryTraceUid&  exportActivityID,
                const TelemetryTraceUid&  importActivityID,
                const char* exceptionDetails,
                const char* transcoderVersion) = 0;

            virtual void Export3DModelEnd(
                const TelemetryTraceUid&  exportActivityID,
                const TelemetryTraceUid&  importActivityID,
                bool success,
                const char* exceptionDetails,
                int durationMS,
                const char* originalModelExtensionType,
                const char* destinationModelExtensionType,
                size_t vertexCount,
                size_t indexCount,
                size_t textureCount,
                int64_t vertexBufferMemory,
                int64_t indexBufferMemory,
                int64_t textureMemory,
                unsigned int numAnimations,
                unsigned int numBones,
                unsigned int animationTypes,
                float totalAnimationDuration,
                const char* transcoderVersion) = 0;

            /// \brief Set a tag to identify telemetry mode
            /// Should not be called directly; instead, use
            /// Engine::ChangeTelemetryMode
            virtual void SetTag(const std::string& tag) = 0;
        };
    }
}
