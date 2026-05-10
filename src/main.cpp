#include "platform/sdl/SDLDisplay.h"

int main(){
    SDLDisplay display;

    App app = display.initSdl();

    while (true) {
        display.presentScene(app);
        display.eventLoop();
    }

    return 0;
}