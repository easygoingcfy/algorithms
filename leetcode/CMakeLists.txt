cmake_minimum_required(version 3.10)
project(leetcode)

add_executable(${PROJECT_NAME})

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/question)

file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")