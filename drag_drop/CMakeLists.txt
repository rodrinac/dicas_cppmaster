cmake_minimum_required(VERSION 2.8)

project(drag_drop)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static")

add_executable(${PROJECT_NAME} "src/main.cpp")
