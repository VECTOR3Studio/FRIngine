cmake_minimum_required(VERSION 3.19)

project(asciid
    VERSION 0.0.1
    DESCRIPTION "Simple 2D Game Engine"
    LANGUAGES CXX
)

# Enforce C++20 globally
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find SFML 3.0 on macOS
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_subdirectory(src)