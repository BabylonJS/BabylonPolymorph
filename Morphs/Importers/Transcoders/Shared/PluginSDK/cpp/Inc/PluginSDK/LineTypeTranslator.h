/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <map>

namespace Spectre {
    namespace Transcoder {
        template<typename T>
        class LineTypeTranslator
        {
        public:
            ~LineTypeTranslator() {};

            explicit LineTypeTranslator(std::map<std::string, T>& typeMap);
            inline T LookUp(const std::string& option) const;

        protected:
            std::map<std::string, T> m_map;
        };

        template <typename T>
        LineTypeTranslator<T>::LineTypeTranslator(std::map<std::string, T>& typeMap)
        {
            m_map = typeMap;
        }

        template <typename T>
        T LineTypeTranslator<T>::LookUp(const std::string& option) const
        {
            auto enumMapIterator = m_map.find(option);
            if (enumMapIterator == m_map.end())
            {
                return static_cast<T>(0);
            }

            return enumMapIterator->second;
        }
    }
}