cmake_minimum_required(VERSION 3.10.2)
project(openthread-border-router)

set(CMAKE_BUILD_TYPE Debug)

# Add debug flags explicitly if needed
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_subdirectory(agent)
add_subdirectory(common)
