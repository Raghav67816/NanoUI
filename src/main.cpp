#include "platform/sdl/SDLDisplay.h"
#include "platform/sdl/SDLWindow.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {
    SDLDisplay display(
        128,
        64
    );

    SDLWindow window(&display);

    window.create();
    window.loop();
}
