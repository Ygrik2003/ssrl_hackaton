cmake_minimum_required(VERSION 3.28)

project(yg_engine VERSION 0.0.1 LANGUAGES C CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs)
add_subdirectory(modules)

file(
    GLOB_RECURSE
    engine_sources
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/*.cxx
    ${CMAKE_CURRENT_LIST_DIR}/*.hxx)
list(REMOVE_ITEM engine_sources ${CMAKE_CURRENT_LIST_DIR}/main.cxx)

add_library(yg_engine SHARED ${engine_sources})
target_include_directories(yg_engine PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(yg_engine PRIVATE SDL3::SDL3 libs::glad PUBLIC imgui::imgui)
set_target_properties(yg_engine PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(yg::engine ALIAS yg_engine)

add_executable(yg_engine_runner ${CMAKE_CURRENT_LIST_DIR}/main.cxx)

target_compile_definitions(yg_engine_runner PUBLIC YG_ENGINE_MAIN)
target_link_libraries(yg_engine_runner PRIVATE yg::engine)
