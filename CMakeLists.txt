cmake_minimum_required(VERSION 3.10)

project(NanoUI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_subdirectory(lib/NanoUI/platform/sdl)