#pragma once
#include <string>
#include <vector>

namespace nenresourcemanager
{
    class ILoader
    {
    public:
        virtual ~ILoader() = default;

        virtual std::vector<char> LoadRawData(const std::string &path) = 0;
    };
}