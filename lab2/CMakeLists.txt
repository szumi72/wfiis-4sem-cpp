cmake_minimum_required(VERSION 3.10)

project(zad)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(zad
    src/main.cpp

)

target_include_directories(zad PRIVATE include)

target_compile_options(zad PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)