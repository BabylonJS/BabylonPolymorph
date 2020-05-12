/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "../CoreUtilsPch.h"

#include <CoreUtils/Math/SimpleMath.h>
#include <CoreUtils/Math/BabylonMath.h>
#include <CoreUtils/Tweening/TweenManager.h>

#include <vector>
#include <algorithm>

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            void TweenManager::Update()
            {
                decltype(m_tweens) tweensToRemove;
                auto currentTime = m_internalClock->Now();

                // Add all tweens from the staging vector in to the array of active tweens
                {
                    std::lock_guard<std::mutex> lock(m_mutex);

                    m_tweens.insert(std::end(m_tweens), std::begin(m_tweensToAdd), std::end(m_tweensToAdd));
                    m_tweensToAdd.clear();
                }

                for (auto tween : m_tweens)
                {
                    bool reachedEnd = false;
                    bool isTweenableTypeStillAlive = true;
                    if (!tween->Cancelled)
                    {
                        std::chrono::duration<double> elapsedSeconds = currentTime - tween->StartTime;
                        std::chrono::duration<double> singleLoopDurationSeconds = tween->LoopDuration;
                        auto normalisedTime = elapsedSeconds / singleLoopDurationSeconds;

                        //  There are two concepts:
                        //  1. progressTimeForSingleLoop which is telling us progress in terms of elapsed time
                        //      where 0.0 meaning start, and 1.0 is that requested duration has elapsed

                        //  2. interpolationValue is telling us where we are between A and B interpolation points
                        //      0.0 meaning we are at point A
                        //      1.0 meaning we are at point B

                        auto interpolationValue = 0.0;
                        auto progressTimeForSingleLoop = 0.0;
                        int loopNumber = static_cast<int>(normalisedTime);
                        reachedEnd = (loopNumber >= tween->LoopCount);
                        switch (tween->LoopType)
                        {
                            case TweenLoopType::Repeat:
                                if (reachedEnd)
                                {
                                    interpolationValue = 1.0;
                                }
                                else
                                {
                                    interpolationValue = Babylon::Utils::Math::Fraction(normalisedTime);
                                    progressTimeForSingleLoop = interpolationValue;
                                }
                                break;
                            case TweenLoopType::Bounce:
                                if (reachedEnd)
                                {
                                    interpolationValue = 0.0;
                                }
                                else
                                {
                                    interpolationValue = Babylon::Utils::Math::Fraction(normalisedTime);
                                    progressTimeForSingleLoop = interpolationValue;
                                }

                                // A single bounce loop goes from 0 to 1 back to 0
                                interpolationValue *= 2.0;
                                bool reverse = interpolationValue >= 1.0;
                                if (reverse)
                                {
                                    interpolationValue = 2.0 - interpolationValue;
                                }
                                break;
                        }

                        /// Tween and check if variable hold by tween is still alive
                        isTweenableTypeStillAlive = tween->TweenableType->Tween(interpolationValue, tween->Curve.get());


                        if (isTweenableTypeStillAlive)
                        {
                            if (tween->ProgressCallback)
                            {
                                tween->ProgressCallback((loopNumber + progressTimeForSingleLoop) / static_cast<double>(tween->LoopCount));
                            }
                        }
                    }

                    if (reachedEnd || tween->Cancelled || !isTweenableTypeStillAlive)
                    {
                        /// Fire callback unless tweenable type is no longer alive
                        if (tween->FinishedCallback && isTweenableTypeStillAlive)
                        {
                            tween->FinishedCallback();
                        }
                        //  Add them to pending removal vector
                        tweensToRemove.push_back(tween);
                    }
                }

                //  Remove completed tweens
                for (const auto& tween : tweensToRemove)
                {
                    m_tweens.erase(std::remove(m_tweens.begin(), m_tweens.end(), tween), m_tweens.end());
                }
            }
        }// end Tweening
    }// end Utils
}// end Babylon
