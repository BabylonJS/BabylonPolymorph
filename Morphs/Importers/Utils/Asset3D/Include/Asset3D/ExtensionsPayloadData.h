/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <map>

namespace Babylon
{
    namespace Transcoder
    {
        class ExtensionsPayloadData
        {
            // ExtensionsPayloadData contains a map of maps;
            // Each map (PayloadMap) has all extensions stored in a particular glTF property, e.g. mesh, node
            // Each extension (ExtensionMap) in this glTF property is stored as a mapping from a string key or name to a string value
        public:
            using PayloadStr = std::shared_ptr<const std::string>;

            struct ExtensionMapStruct {
                std::map<const std::string, PayloadStr> ExtensionMap;
            };

            struct PayloadMapStruct {
                std::map<std::string, ExtensionMapStruct> PayloadMap;
            };

            inline void AddItem(const std::string& key, const std::string& extensionKey, const std::string& extensionValue)
            {
                if (!key.empty() && !extensionKey.empty() && !extensionValue.empty())
                {
                    m_extensionsPayloadMap.PayloadMap[key].ExtensionMap[extensionKey] =
                        std::make_shared<std::string>(extensionValue);
                }
            }

            // Retrieve all extensions of a node, mesh etc, as a map
            inline ExtensionMapStruct GetExtensions(const std::string& key) const
            {
                auto it = m_extensionsPayloadMap.PayloadMap.find(key);
                if (it == m_extensionsPayloadMap.PayloadMap.end())
                {
                    return ExtensionMapStruct();
                }
                return it->second;
            }

            // Retrieve specific extension of a node, mesh, etc
            inline PayloadStr GetExtension(const std::string& key, const std::string& extensionKey) const
            {
                ExtensionMapStruct extensions = GetExtensions(key);
                auto it = extensions.ExtensionMap.find(extensionKey);
                if (it == extensions.ExtensionMap.end())
                {
                    return PayloadStr();
                }
                return it->second;
            }

        private:
            PayloadMapStruct m_extensionsPayloadMap;
        };
    }
}