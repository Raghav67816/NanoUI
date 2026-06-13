#include <string>

#include "lib/NanoUI/core/Stack.h"

#include "lib/NanoUI/platform/sdl/SDLDisplay.h"
#include "lib/NanoUI/platform/sdl/SDLWindow.h"

#include "lib/NanoUI/widgets/Label.h"
#include "lib/NanoUI/widgets/Screen.h"
#include "lib/NanoUI/widgets/ProgressBar.h"
#include "lib/NanoUI/widgets/ScrollWidget.h"

#include "lib/NanoUI/layouts/Column.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64


SDLDisplay display(
    DISPLAY_WIDTH, 
    DISPLAY_HEIGHT
);

Color white = {255, 255, 255};
Color black = {0, 0, 0};

Graphics gfx(&display);

SDLWindow window(&display);

int currentProg = 0;

Stack screenStack(display, gfx);

Column root_layout(0, 0, display.getWidth(), display.getHeight() - 10);

Screen screen_a(&display, "Screen A");

ScrollWidget scrollWidget(0, 0, DISPLAY_WIDTH - 8, DISPLAY_HEIGHT - 14);

void setup() {
    root_layout.addChild(&scrollWidget);

    screen_a.addChild(&root_layout);
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