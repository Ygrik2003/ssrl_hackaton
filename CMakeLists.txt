cmake_minimum_required(VERSION 3.28)

project(Tanchiki C CXX)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

option(YG_USE_EXAMPLE "Compile only examples" ON)

if(${YG_USE_EXAMPLE})
    add_subdirectory(examples)
else()
    add_subdirectory(src)
endif()
