#pragma once
#include <string>
#include <vector>

namespace nenresourcemanager
{
    /// @brief Interface for loaders that load raw data from files.
    class ILoader
    {
    public:
        virtual ~ILoader() = default;

        /// @brief Loads raw data from a specified file path.   
        /// @param path The file path to load the raw data from.
        /// @return A vector containing the loaded raw data.
        virtual std::vector<char> LoadRawData(const std::string &path) = 0;
    };
}