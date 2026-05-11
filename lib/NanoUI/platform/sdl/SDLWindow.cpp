//
// Created by cooper on 5/10/26.
//

#include "SDLWindow.h"

void SDLWindow::create() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("failed to initialize SDL\n");
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    this->window = SDL_CreateWindow(
        "Simulated Display",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->w,
        this->h,
        0
    );

    if (this->window == nullptr) {
        printf("failed to create window\n");
    }

    renderer = SDL_CreateRenderer(
        this->window,
        -1,
        0
    );

    if (!this->renderer) {
        printf("failed to create renderer\n");
        exit(1);
    }

    this->texture = SDL_CreateTexture(
        this->renderer,
        SDL_PIXELFORMAT_RGB24,
        SDL_TEXTUREACCESS_STREAMING,
        display->getWidth(),
        display->getHeight()
    );

    if (!this->texture) {
        printf("failed to create texture\n");
        exit(1);
    }

    SDL_SetRenderDrawColor(
        this->renderer,
        128,
        128,
        128,
        SDL_ALPHA_OPAQUE
    );
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

void SDLWindow::destroy() {
    SDL_DestroyTexture(this->texture);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

void SDLWindow::update() {

    auto& fb = display->getFrameBuffer();
    printf("Pixel 0: %d, %d, %d  \n", fb[0], fb[1], fb[2]);

    SDL_SetRenderDrawColor(
        this->renderer,
        windowBg.r,
        windowBg.g,
        windowBg.b,
        SDL_ALPHA_OPAQUE
    );
    SDL_RenderClear(this->renderer);

    int scaled_w = display->getWidth() * this->scale;
    int scaled_h = display->getHeight() * this->scale;

    this->destRect = {
        (this->w - scaled_w) / 2,
        (this->h - scaled_h) / 2,
        scaled_w,
        scaled_h
    };
    SDL_SetRenderDrawColor(
        this->renderer,
        0,
        0,
        0,
        SDL_ALPHA_OPAQUE
    );

    SDL_UpdateTexture(this->texture, nullptr, display->getFrameBuffer().data(), display->getWidth() * 3);
    SDL_RenderCopy(this->renderer, this->texture, nullptr, &this->destRect);
    SDL_RenderPresent(this->renderer);
}

void SDLWindow::loop(std::function<void()> applicationLoop, std::function<void()> setupLoop) {
    setupLoop();
    while (this->isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    isRunning = false;
                    break;

                case SDL_MOUSEWHEEL:
                    if (event.wheel.y > 0) {
                        this->scale += 1;
                        printf("Scaling up: %d \n", this->scale);
                    }

                    if (event.wheel.y < 0) {
                        this->scale -= 1;
                        printf("Scaling down: %d \n", this->scale);
                    }
                    break;

                default:
                    break;
            }
        }

        applicationLoop();
        this->update();
    }

    this->destroy();
}

