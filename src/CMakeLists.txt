cmake_minimum_required(VERSION 3.28)

find_package(functions)

# add_subdirectory(api)
# add_subdirectory(game)

add_executable(tanks_game_online main.cxx)
yg_add_resource_folder(
    TARGETS
    tanks_game_online
    RESOURCES
    ${CMAKE_SOURCE_DIR}/data)

# target_link_libraries(tanks PRIVATE game::api game::game)
