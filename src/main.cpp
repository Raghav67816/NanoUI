#include "platform/sdl/SDLDisplay.h"
#include "platform/sdl/SDLWindow.h"

#include "core/Graphics.h"
#include "widgets/Screen.h"
#include "core/Stack.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


SDLDisplay display(
    128,
    64
);

Graphics gfx(&display);

SDLWindow window(&display);

Stack screenStack(display, gfx);
Screen screen_a(&display, "Screen A");

void setup() {
    screenStack.addScreen(screen_a);

    display.clear();
    screenStack.goTo(display, screen_a, gfx);
    display.flush();
}

void loop() {
    screenStack.renderApp(gfx);
    display.flush();
}

int main() {
    window.create();
    window.loop(loop, setup);
}