find_package(SDL2 REQUIRED)

add_executable(
    NanoUI_SDL

    SDLDisplay.cpp

    ../../core/Graphics.cpp
    ../../core/Widget.cpp

    ../../widgets/Label.cpp
    ../../widgets/ProgressBar.cpp
    ../../widgets/ScrollWidget.cpp
    ../../widgets/Screen.cpp

    ../../layouts/Layout.cpp
    ../../layouts/Column.cpp

    ../../../../src/main.cpp
)

include_directories(${SDL2_INCLUDE_DIRS})

target_include_directories(
    NanoUI_SDL PRIVATE

    ../../
    ../../core
    ../../widgets
    ../../layouts
)

target_link_libraries(NanoUI_SDL PRIVATE SDL2::SDL2)