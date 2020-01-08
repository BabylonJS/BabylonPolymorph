/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Hash.h>
#include <CoreUtils/Math/SimpleMath.h>
#include <Asset3D/BoundingBox.h>
#include <Asset3D/ExtensionsPayloadData.h>

namespace Spectre
{
    namespace Transcoder
    {
        // Base class corresponding to glTFProperty
        class ITraversableBase
        {
        public:
            virtual ~ITraversableBase() = default;

            uint32_t GetId() const { return m_id; }
            std::string GetIdString() const { return std::to_string(m_id); }

            void SetExtras(std::string extras) { m_gltfExtras = std::move(extras); }
            bool HasExtras() const { return !m_gltfExtras.empty(); }
            const std::string& GetExtras() const { return m_gltfExtras; }

            void SetExtensions(ExtensionsPayloadData extensions) { m_extensionsPayload = std::move(extensions); }
            const ExtensionsPayloadData& GetExtensions() const { return m_extensionsPayload; }

            /// Add a generic payload item to this node
            void AddExtensionsItem(const std::string& key, const std::string& extensionKey, const std::string& extensionValue)
            {
                m_extensionsPayload.AddItem(key, extensionKey, extensionValue);
            }

            // Retrieve all extensions of a particular node, mesh etc, as a map
            const ExtensionsPayloadData::ExtensionMapStruct GetExtensions(const std::string& key) const
            {
                return m_extensionsPayload.GetExtensions(key);
            }

            // Retrieve specific extension of a particular node, mesh, etc
            const ExtensionsPayloadData::PayloadStr GetExtension(const std::string& key, const std::string& extensionKey) const
            {
                return m_extensionsPayload.GetExtension(key, extensionKey);
            }

        protected:
            // Start m_id from 1, since there could be some places in the code that treat 0 specially
            ITraversableBase() : m_id(++s_idCount), m_extensionsPayload(), m_gltfExtras() {}

            // Allow move-construction
            ITraversableBase(ITraversableBase&&) = default;

            // Copying should never happen, so disable copy-constructor and copy-assignment
            ITraversableBase(const ITraversableBase&) = delete;
            ITraversableBase& operator=(const ITraversableBase&) = delete;

            // Disable move-assignment
            ITraversableBase& operator=(ITraversableBase&&) = delete;

        private:
            uint32_t              m_id;
            ExtensionsPayloadData m_extensionsPayload;  // Every traversable can have optional GLTF extensions
            std::string           m_gltfExtras;         // Every traversable can have an optional GLTF extras string

            static uint32_t s_idCount;
        };

        // Base class corresponding to glTFChildOfRootProperty
        class ITraversableWithName : public ITraversableBase
        {
        public:
            void SetName(std::string name) { m_name = std::move(name); }
            const std::string& GetName() const { return m_name; }

        protected:
            ITraversableWithName() = default;

        private:
            std::string m_name;
        };
    }
}
