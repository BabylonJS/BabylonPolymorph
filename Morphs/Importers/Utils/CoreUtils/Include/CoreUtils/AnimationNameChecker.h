/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <unordered_set>
#include <string>

namespace Babylon
{
    namespace Utils
    {
        // [Office] Animation names need to be non-empty and unique
        class AnimationNameChecker
        {
        public:
            AnimationNameChecker()
            {
                m_disallowedAnimationNames.emplace(""); // Do not allow empty animation name.
            }

            std::string GetUniqueName(const std::string& animationName)
            {
                // Modify the animation name, if it is a name that is not allowed.
                int uniqueNameCount = 0;
                std::string uniqueName = animationName;
                std::string baseName = animationName.empty() ? k_animationNamePrefix : animationName;
                while (!m_disallowedAnimationNames.insert(uniqueName).second)
                {
                    uniqueName = baseName + std::to_string(uniqueNameCount);
                    uniqueNameCount++;
                }
                return uniqueName;
            }

        private:
            const std::string k_animationNamePrefix = "animation_";
            std::unordered_set<std::string> m_disallowedAnimationNames;
        };

    }
}
