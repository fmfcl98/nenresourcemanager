cmake_minimum_required(VERSION 3.15)
project(NenResourceManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(NenResourceManager
    src/ResourceManager/ResourceManager.cpp
    include/ResourceManager/ResourceManager.h
    include/ResourceManager/IResourceFactory.h
    include/ResourceManager/ILoader.h
)

target_include_directories(NenResourceManager PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS NenResourceManager DESTINATION lib)
install(DIRECTORY include/NenResourceManager DESTINATION include)