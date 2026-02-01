#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <typeindex>
#include "IResourceFactory.h"
#include "ILoader.h"

namespace nenresourcemanager
{
    /// @brief Manages resource loading, caching, and factory registration.
    class ResourceManager
    {
    public:
        /// @brief Constructs a ResourceManager with a given loader.
        /// @param loader The loader used to load raw data.
        explicit ResourceManager(ILoader &loader) : m_loader(loader) {}

        /// @brief Registers a resource factory for a specific resource type.
        /// @tparam T The type of the resource.
        /// @param factory A unique pointer to the resource factory.
        template <typename T>
        void RegisterFactory(std::unique_ptr<IResourceFactory> factory)
        {
            m_factories[typeid(T)] = std::move(factory);
        }

        /// @brief Clears the resource cache, removing all loaded resources from RAM.
        void clearCache()
        {
            m_resourceCache.clear();
        }

        /// @brief Clears all registered resource factories.
        void clearFactories()
        {
            m_factories.clear();
        }

        /// @brief Loads a resource of a given type from a specified path.
        /// @tparam T The type of the resource to load.
        /// @param path The file path to load the resource from.
        /// @return A shared pointer to the loaded resource.
        template <typename T>
        std::shared_ptr<T> Load(const std::string &path)
        {
            return std::static_pointer_cast<T>(LoadInternal(path, typeid(T)));
        }

    private:
        /// @brief Internally loads a resource of a given type from a specified path.
        /// @param path The file path to load the resource from.
        /// @param type The type of the resource to load.
        /// @return A shared pointer to the loaded resource.
        std::shared_ptr<void> LoadInternal(const std::string &path, std::type_index type);

        /// @brief Map of resource factories indexed by resource type.
        std::unordered_map<std::type_index, std::unique_ptr<IResourceFactory>> m_factories;
        /// @brief Cache of loaded resources indexed by a combination of path and type.
        std::unordered_map<std::string, std::shared_ptr<void>> m_resourceCache;
        /// @brief Reference to the loader used to load raw data.
        ILoader &m_loader;
    };
}