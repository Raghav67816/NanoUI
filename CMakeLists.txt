cmake_minimum_required(VERSION 3.10)
project(NanoUI_Simulation_Project)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(SDLTTF_VENDORED ON)

find_package(SDL2 REQUIRED)

add_executable(NanoUI_SDL
    src/main.cpp
    lib/NanoUI/platform/sdl/SDLDisplay.cpp
    lib/NanoUI/platform/sdl/SDLDisplay.h
    lib/NanoUI/platform/sdl/SDLWindow.cpp
    lib/NanoUI/platform/sdl/SDLWindow.h


    lib/NanoUI/core/Graphics.cpp
    lib/NanoUI/core/Widget.cpp
    lib/NanoUI/core/Stack.cpp
    # lib/NanoUI/core/OLEDisplay.cpp

    lib/NanoUI/widgets/Label.cpp
    lib/NanoUI/widgets/ProgressBar.cpp
    lib/NanoUI/widgets/ListWidget.cpp
    lib/NanoUI/widgets/ListItem.h
    lib/NanoUI/widgets/Screen.cpp
    lib/NanoUI/widgets/Button.cpp


    lib/NanoUI/layouts/Layout.cpp
    lib/NanoUI/layouts/Column.cpp
    lib/NanoUI/layouts/Row.cpp
)

target_include_directories(NanoUI_SDL PRIVATE

    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    

    ${CMAKE_CURRENT_SOURCE_DIR}/lib/NanoUI
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/NanoUI/core
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/NanoUI/widgets
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/NanoUI/layouts
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/NanoUI/platform/sdl
)

target_link_libraries(NanoUI_SDL PRIVATE SDL2::SDL2 SDL2_ttf)