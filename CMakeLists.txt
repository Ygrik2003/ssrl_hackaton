cmake_minimum_required(VERSION 3.28)

project(Tanchiki CXX C)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

option(YG_MODULE_SDL_REBUILD "If ON -- rebuild SDL from source" OFF)
option(YG_MODULE_GLM_REBUILD "If ON -- rebuild glm from source" ON)

add_subdirectory(modules)
add_subdirectory(src)
