cmake_minimum_required(VERSION 3.28)

add_library(api SHARED ${CMAKE_SOURCE_DIR}/src/config.h base.cxx base.h)
target_include_directories(api PUBLIC ${CMAKE_CURRENT_LIST_DIR}
                                      ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(
    api
    PUBLIC sfml-graphics
           sfml-system
           sfml-window
           underscore)

add_library(game::api ALIAS api)
