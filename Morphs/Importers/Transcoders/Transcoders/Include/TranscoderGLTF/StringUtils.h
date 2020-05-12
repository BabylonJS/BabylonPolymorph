#pragma once

#include <algorithm>
#include <functional>

namespace Babylon
{
    namespace Transcoder
    {
        namespace GLTF
        {
            class StringUtils
            {
            public:

                static std::string RemoveAllWhiteSpaces(std::string str)
                {
                    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
                    str.erase(end_pos, str.end());
                    return str;
                }
            };
        }
    }
}