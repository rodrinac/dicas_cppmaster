cmake_minimum_required(VERSION 2.8)

project(regex_ex)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} "src/main.cpp")
