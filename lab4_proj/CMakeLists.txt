cmake_minimum_required(VERSION 3.10)

project(project1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "src/*.cpp")
#jakby nie działały pliki to albo jeszcze raz cmake albo recznie dodac te .cpp
add_executable(proj
    ${SOURCES}
)

target_include_directories(proj PRIVATE include)

target_compile_options(proj PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)