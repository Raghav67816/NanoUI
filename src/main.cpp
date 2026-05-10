#include "platform/sdl/SDLDisplay.h"

int main(){
    SDLDisplay display{};

    display.initSdl();

    while (true) {
        display.eventLoop();
    }

    return 0;
}