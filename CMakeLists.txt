cmake_minimum_required(VERSION 3.20)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "*.cpp")
list(FILTER SRC EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/build/")
list(FILTER SRC EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/.git/")

add_library(leetcode_solutions OBJECT ${SRC})
target_compile_features(leetcode_solutions PRIVATE cxx_std_23)
target_include_directories(leetcode_solutions PRIVATE "${CMAKE_SOURCE_DIR}")