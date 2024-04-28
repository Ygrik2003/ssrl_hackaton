cmake_minimum_required(VERSION 3.28)

add_library(
    game
    INTERFACE
    game.h
    game.cxx
    animation.h
    animation.cxx)
target_link_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(game::game ALIAS game)
