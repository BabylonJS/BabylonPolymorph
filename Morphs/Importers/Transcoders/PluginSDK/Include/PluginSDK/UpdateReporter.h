/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Framework/Async.h>
#include <CoreUtils/SmartThrow.h>

namespace Babylon
{
    namespace Transcoder
    {
        /*
        * Reports the completed percentage of Transcoding
        */
        class UpdateReporter
        {
        public:
            explicit UpdateReporter(
                float parsingWeight = .5f,
                float encodingWeight = .5f);

            /*
            * Reports what percentage of parsing that was completed.
            */
            inline void ReportCompletedParsing(float percentage);

            /*
            * Reports what percentage of encoding that was completed.
            */
            inline void ReportCompletedEncoding(float percentage);

            /*
            * Reports the additional percentage of parsing that was completed.
            */
            inline void ReportAdditionalCompletedParsing(float percentage);

            /*
            * Reports the additional percentage of encoding that was completed.
            */
            inline void ReportAdditionalCompletedEncoding(float percentage);

            /*
            * Updates the weights of the different parts and report
            * the updated completed percentage.
            */
            inline void SetWeights(float parsingWeight, float encodingWeight);

            /*
            * Sets the callback to report the progress.
            */
            inline void SetProgressReporter(ProgressIndicatorReporter percentageReporter);

        protected:
            inline void ReportProgress();

            float m_parsingWeight;
            float m_encodingWeight;
            float m_parsingPercentage;
            float m_encodingPercentage;
            int m_lastPercentageReported;
            ProgressIndicatorReporter m_percentageReporter;
        };
    }
}

inline Babylon::Transcoder::UpdateReporter::UpdateReporter(
    float parsingWeight,
    float encodingWeight)
    : m_parsingWeight(parsingWeight),
    m_encodingWeight(encodingWeight),
    m_parsingPercentage(0.f),
    m_encodingPercentage(0.f),
    m_lastPercentageReported(-1),
    m_percentageReporter(nullptr)
{
    if (parsingWeight + encodingWeight != 1.f)
    {
        throw Babylon::Utils::BabylonException("The weights must sum up to 1.");
    }
}

inline void Babylon::Transcoder::UpdateReporter::ReportCompletedParsing(float percentage)
{
    m_parsingPercentage = percentage;
    ReportProgress();
}

inline void Babylon::Transcoder::UpdateReporter::ReportCompletedEncoding(float percentage)
{
    m_encodingPercentage = percentage;
    ReportProgress();
}

inline void Babylon::Transcoder::UpdateReporter::ReportAdditionalCompletedParsing(float percentage)
{
    m_parsingPercentage += percentage;
    ReportProgress();
}

inline void Babylon::Transcoder::UpdateReporter::ReportAdditionalCompletedEncoding(float percentage)
{
    m_encodingPercentage += percentage;
    ReportProgress();
}

inline void Babylon::Transcoder::UpdateReporter::SetWeights(float parsingWeight, float encodingWeight)
{
    if (parsingWeight + encodingWeight != 1.f)
    {
        throw Babylon::Utils::BabylonException("The weights must sum up to 1.");
    }

    m_parsingWeight = parsingWeight;
    m_encodingWeight = encodingWeight;
    ReportProgress();
}

inline void Babylon::Transcoder::UpdateReporter::SetProgressReporter(ProgressIndicatorReporter percentageReporter)
{
    m_percentageReporter = percentageReporter;
}

inline void Babylon::Transcoder::UpdateReporter::ReportProgress()
{
    // TODO: Make it configurable
    auto calculatedPercentage = (m_parsingPercentage * m_parsingWeight) + (m_encodingPercentage * m_encodingWeight);
    auto percentageCompleted = calculatedPercentage < 1.0f ? calculatedPercentage : 1.f;

    //the below code ensures that the percentage is only reported when it changes by >= 1 percent
    //This ensures that the progress callback will be invoked at most 100 times.
    auto percentile = static_cast<int>(percentageCompleted * 100);
    if (m_percentageReporter && percentile > m_lastPercentageReported)
    {
        m_lastPercentageReported = percentile;
        m_percentageReporter(percentageCompleted);
    }
}
