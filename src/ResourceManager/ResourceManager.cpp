#include "ResourceManager/ResourceManager.h"
#include <iostream>
#include <vector>

namespace nenresourcemanager
{

    std::shared_ptr<void> ResourceManager::LoadInternal(const std::string &path, std::type_index type)
    {
        auto cacheKey = path + type.name();
        if (m_resourceCache.contains(cacheKey))
        {
            return m_resourceCache[cacheKey];
        }

        auto factoryIt = m_factories.find(type);
        if (factoryIt == m_factories.end())
        {
            std::cerr << "No factory registered for this type!" << std::endl;
            return nullptr;
        }

        std::vector<char> raw = m_loader.LoadRawData(path);
        if (raw.empty())
        {
            return nullptr;
        }

        auto resource = factoryIt->second->create(raw);
        if (resource)
        {
            m_resourceCache[cacheKey] = resource;
        }

        return resource;
    }

}