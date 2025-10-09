cmake_minimum_required(VERSION 3.16)
project(LearningCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(learning_cpp
    src/main.cpp
    src/utilities.cpp
    src/basics.cpp
    src/oop.cpp
    src/advanced.cpp
)

target_include_directories(learning_cpp PRIVATE include)
