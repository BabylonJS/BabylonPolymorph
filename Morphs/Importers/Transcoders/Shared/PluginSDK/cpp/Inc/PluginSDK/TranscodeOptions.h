/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <functional>
#include <unordered_map>

#include <CoreUtils/SmartThrow.h>

namespace Babylon
{
    namespace Transcoder
    {
        struct TranscodeOption
        {
            std::string name;
            std::string help;
            std::function<void(const std::string&)> deserializer;
        };

        class TranscodeOptions
        {
        public:
            TranscodeOptions() = default;
            virtual ~TranscodeOptions() = default;
            void Parse(const std::unordered_map<std::string, std::string>& optionValues);
            std::string GenerateHelp() const;

        protected:
            void AddOption(TranscodeOption&& option);

        private:
            std::unordered_map<std::string, TranscodeOption> m_options;
        };

        template<typename TTranscodeOptions>
        TTranscodeOptions ParseOptions(const std::unordered_map<std::string, std::string>& optionValues)
        {
            TTranscodeOptions options;
            options.Parse(optionValues);
            return options;
        }

        template<typename TTranscodeOptions>
        std::string GetHelp()
        {
            TTranscodeOptions options;
            return options.GenerateHelp();
        }
    }
}