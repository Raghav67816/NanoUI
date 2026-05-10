#pragma once
#include "core/Display.h"

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
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


    // init SDL window
    void initSdl();

    void eventLoop();
};
