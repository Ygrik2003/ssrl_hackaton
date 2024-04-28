cmake_minimum_required(VERSION 3.28)

add_library(underscore INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/underscore/lib/underscore.h)
target_include_directories(underscore INTERFACE ${CMAKE_CURRENT_LIST_DIR}/underscore/lib/)