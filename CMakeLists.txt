cmake_minimum_required(VERSION 3.16)

project(NenResourceManager
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(NenResourceManager
    main.cpp
)

target_include_directories(NenResourceManager
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

