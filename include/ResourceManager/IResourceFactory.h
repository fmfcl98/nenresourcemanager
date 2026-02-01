#pragma once
#include <memory>
    
namespace nenresourcemanager 
{
    /// @brief Interface for resource factories that create resources from raw data.
    class IResourceFactory
    {
    public:
        virtual ~IResourceFactory() = default;
        /// @brief Creates a resource from raw data.
        /// @param rawData The raw data used to create the resource.
        /// @return A shared pointer to the created resource.
        virtual std::shared_ptr<void> create(const std::vector<char>& rawData) = 0;
        
    };

}