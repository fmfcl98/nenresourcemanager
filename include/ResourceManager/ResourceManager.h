#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <typeindex>
#include "IResourceFactory.h"
#include "ILoader.h"

namespace nenresourcemanager {
    class ResourceManager {
    public:
        explicit ResourceManager(ILoader& loader) : m_loader(loader) {}

        template <typename T>
        void RegisterFactory(std::unique_ptr<IResourceFactory> factory) {
            m_factories[typeid(T)] = std::move(factory);
        }

        /// @brief Loads a resource of a given type from a specified path.
        /// @tparam T The type of the resource to load.
        /// @param path The file path to load the resource from.
        /// @return A shared pointer to the loaded resource.
        template <typename T>
        std::shared_ptr<T> Load(const std::string &path) {
            return std::static_pointer_cast<T>(LoadInternal(path, typeid(T)));
        }

    private:
        /// @brief Internally loads a resource of a given type from a specified path.
        /// @param path The file path to load the resource from.
        /// @param type The type of the resource to load.
        /// @return A shared pointer to the loaded resource.
        std::shared_ptr<void> LoadInternal(const std::string& path, std::type_index type);

        /// @brief Map of resource factories indexed by resource type.
        std::unordered_map<std::type_index, std::unique_ptr<IResourceFactory>> m_factories;
        /// @brief Cache of loaded resources indexed by a combination of path and type.
        std::unordered_map<std::string, std::shared_ptr<void>> m_resourceCache;
        /// @brief Reference to the loader used to load raw data.
        ILoader& m_loader;
    };
}