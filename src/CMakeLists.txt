cmake_minimum_required(VERSION 3.28)

add_library(api SHARED base.h base.cpp config.h)
target_include_directories(api PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(api PUBLIC sfml-graphics sfml-system sfml-window underscore)


add_executable(tanchiki main.cpp)
target_link_libraries(tanchiki PRIVATE api)

# Add symlink to /misc dir
set(source "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(destination "${CMAKE_CURRENT_BINARY_DIR}/src")
add_custom_command(
    TARGET tanchiki POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}"
)