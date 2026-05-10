#include <SDL.h>
#include "SDLDisplay.h"

void initSdl(){
    int renderFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    App app;
    app.window = SDL_CreateWindow(
        "Nano UI Simulated Display",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        windowFlags
        );

    if (!app.window) {
        printf("failed to create window: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, renderFlags);

    if (!app.renderer) {
        printf("failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}

void eventLoop() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);

            default:
               break;
        }
    }
}

void SDLDisplay::clear(){}
void SDLDisplay::flush(){}
void SDLDisplay::drawPixel(int x, int y, Color pixelColor){}
int SDLDisplay::getHeight() {
    return 0;
}
int SDLDisplay::getWidth() {
    return 0;
}
