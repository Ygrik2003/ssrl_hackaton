cmake_minimum_required(VERSION 3.28)

project(Tanchiki C CXX)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

add_subdirectory(src)
