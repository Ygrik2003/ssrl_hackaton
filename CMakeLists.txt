cmake_minimum_required(VERSION 3.28)

project(Tanchiki CXX)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

add_subdirectory(modules)
add_subdirectory(src)
