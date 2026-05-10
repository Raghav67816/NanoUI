#include "SDLWindow.h"

void SDLWindow::setDisplaySize(int w, int h) {
    this->displayW = w;
    this->displayH = h;
}

void SDLWindow::initWindow() {
    int renderFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    framebuffer.resize(this->displayW * this->displayH);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow(
        "Nano UI Simulated Display",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        this->windowW,
        this->windowH,
        windowFlags
    );

    if (!app.window) {
        printf("failed to create window: %s\n", SDL_GetError());
        exit(1);
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, renderFlags);
    if (!app.renderer) {
        printf("failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

}

void SDLWindow::presentWindow() {
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);

    SDL_Rect dstRect = {
        32,
        16,
        displayW * 6,
        displayH * 6
    };

    prepareDisplayTexture();

    SDL_RenderCopy(app.renderer, this->displayTexture, nullptr, &dstRect);
    SDL_RenderPresent(app.renderer);
}

void SDLWindow::prepareDisplayTexture() {
    if (this->app.renderer == nullptr) {
        printf("renderer not available");
        exit(1);
    }

    this->displayTexture = SDL_CreateTexture(
        app.renderer,
        SDL_PIXELFORMAT_RGB332,
        SDL_TEXTUREACCESS_STREAMING,
        this->displayW,
        this->displayH
    );
}

void SDLWindow::setPixel(int x, int y, Color pixelColor) {
    uint8_t _pixelColor = 0;
    if (x < 0 || y < 0  || x > this->displayW || y > this->displayH) {
        if (pixelColor.r + pixelColor.g + pixelColor.b >=  3*255) {
            _pixelColor = 1;
        }
        this->framebuffer[y * this->displayW + x] = _pixelColor;
    }
}

void SDLWindow::eventLoop() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                SDL_Quit();
                exit(0);

            default:
                break;
        }
    }
}

