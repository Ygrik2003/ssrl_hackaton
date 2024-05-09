cmake_minimum_required(VERSION 3.28)

find_package(functions)

add_subdirectory(yg_engine)
add_subdirectory(game)

# add_executable(tanchiki config.hxx)
# yg_add_resource_folder(
#     TARGETS
#     tanchiki
#     RESOURCES
#     ${CMAKE_SOURCE_DIR}/data)

# target_link_libraries(tanchiki PRIVATE yg::engine)
