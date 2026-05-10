#pragma once

#include <SDL2/SDL.h>
#include "core/Display.h"

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    Color *backgroundColor;
} App;

/*
SDLDisplay.h

Allows you to develop interface without building for microcontroller
allos better debugging.

The main purpose of this is to make development efficient.
 */
class SDLDisplay: public Display{

    public:
    void clear() override;
    void flush() override;

    void drawPixel(int x, int y, Color pixelColor) override;

    int getHeight() override;
    int getWidth() override;


    App initSdl();
    void eventLoop();
    void presentScene(const App &app);
};
