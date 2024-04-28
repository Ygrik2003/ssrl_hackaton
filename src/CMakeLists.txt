cmake_minimum_required(VERSION 3.28)

add_subdirectory(api)
add_subdirectory(game)

add_executable(tanks main.cpp)
target_link_libraries(tanks PRIVATE game::api game::game)

# Add symlink to /misc dir
add_custom_command(
    TARGET tanks
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/res
        ${CMAKE_CURRENT_BINARY_DIR}/res DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}")
