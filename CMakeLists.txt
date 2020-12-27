# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(untitled main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ws2_32)
