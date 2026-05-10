#pragma once

#include <vector>

#include "SDL.h"
#include "core/Color.h"

struct SDL_App {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    Color *bgColor = nullptr;
};

class SDLWindow {
private:
    int windowW = 800;
    int windowH = 600;

    int displayW = 128;
    int displayH = 64;

    SDL_App app{};

    std::vector<uint8_t> framebuffer;
    SDL_Texture *displayTexture = nullptr;

public:
    SDLWindow(int w, int h): displayW(w), displayH(h) {}

    void setDisplaySize(int w, int h);

    void initWindow();
    void eventLoop();

    void presentWindow();
    void prepareDisplayTexture();

    void setPixel(int x, int y, Color pixelColor);
};
