//
// Created by cooper on 5/10/26.
//

#ifndef NANOUI_SDLWINDOW_H
#define NANOUI_SDLWINDOW_H

#include <SDL2/SDL.h>

#include "SDLDisplay.h"
#include "widgets/Screen.h"


class SDLWindow {
private:
    int w = 800;
    int h = 600;

    int scale = 2;

    int testInt = 0;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *texture = nullptr;

    SDLDisplay *display;

    SDL_Rect destRect;

    Color windowBg = {128, 128, 128};

    bool isRunning = true;

public:
    SDLWindow(SDLDisplay *sDisplay): display(sDisplay) {}

    void create();
    void destroy();

    void update();
    void loop(std::function<void()> applicationLoop, std::function<void()> appSetup);
};
#endif //NANOUI_SDLWINDOW_H
