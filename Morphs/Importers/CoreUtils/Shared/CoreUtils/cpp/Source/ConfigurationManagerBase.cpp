/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <string>

#include <CoreUtils/IConfigurationManager.h>
#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/Pointers.h>

namespace Spectre
{
    namespace Utils
    {
        const ConfigurationDomain     kConfigurationDomain_Standard = L"";
        const ConfigurationDomain     kConfigurationDomain_Internal = L"Internal";

        IConfigurationManager::IConfigurationManager(ConfigurationStateID id, const IConfigurationManagerPtr& parent) :
            m_id(id),
            m_parent(parent)
        {
            if (parent)
            {
                //m_parent->m_children.push_back(shared_from_this());
            }
        }

        IConfigurationManager::~IConfigurationManager()
        {

        }

        ConfigurationStateID IConfigurationManager::GetID() const
        {
            return m_id;
        }

        IConfigurationManagerPtr IConfigurationManager::GetParent() const
        {
            return m_parent;
        }

        ConfigurationDomain IConfigurationManager::GetDomain(ConfigurationPropertyName_ propertyName) const
        {
            if (propertyName.empty())
            {
                throw SpectreInvalidArgException("IConfigurationManager::GetDomain() -- empty string is not a valid property name");
            }

            if (propertyName[0] == '/')
            {
                auto domainStart = 1;
                auto domainEnd = propertyName.find('/', domainStart);
                if (domainEnd == ConfigurationPropertyName::npos)
                {
                    throw SpectreInvalidArgException("IConfigurationManager::GetDomain() -- property domain must begin and end with a slash, e.g. /CustomDomain/Category.Value");
                }

                auto domainName = propertyName.substr(1, domainEnd - domainStart);
                return domainName;
            }
            else
            {
                return kConfigurationDomain_Standard;
            }
        }

        //----------------------------------------------------------
        void IConfigurationManager::ToggleBool(ConfigurationPropertyName_ propertyName)
        {
            // Note: lock is inside SetBool()/GetBool() so this is thread safe.
            SetBool(propertyName, !GetBool(propertyName));
        }

     } // End namespace Utils

} // End namespace Spectre
