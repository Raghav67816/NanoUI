#include <cstdio>
#include "platform/sdl/SDLWindow.h"

int main() {
    printf("starting program...");

    SDLWindow window(800, 600);

    // draw sdl window
    window.initWindow();

    while (true) {
        window.eventLoop();

        window.presentWindow();

        SDL_Delay(50);
    }

    return 0;
}
