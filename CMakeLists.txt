cmake_minimum_required(VERSION 3.28)

project(Tanchiki C CXX)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

option(YG_USE_EXAMPLES "Compile only examples" OFF)

if(${YG_USE_EXAMPLES})
    add_subdirectory(examples)
else()
    add_subdirectory(src)
endif()
