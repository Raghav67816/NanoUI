#include <string>

#include "Label.h"
#include "ProgressBar.h"
#include "ScrollWidget.h"
#include "platform/sdl/SDLDisplay.h"
#include "platform/sdl/SDLWindow.h"

#include "widgets/Label.h"
#include "core/Graphics.h"
#include "widgets/Screen.h"
#include "core/Stack.h"

#include "layouts/Column.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


SDLDisplay display(
    128,
    64
);

Color white = {255, 255, 255};
Color black = {0, 0, 0, };

Graphics gfx(&display);

SDLWindow window(&display);

int currentProg = 0;

Stack screenStack(display, gfx);

Column root_layout(0, 0, display.getWidth(), display.getHeight() - 10);

Label prog(20, 10, "0%", white);
ProgressBar progress_bar(100, 10);

Screen screen_a(&display, "Screen A");

void updateProg() {
    currentProg += 1;
    progress_bar.setProgress(currentProg);
    prog.setText("Writing data....");
}

void setup() {
    root_layout.addChild(&prog);
    root_layout.addChild(&progress_bar);

    screen_a.addChild(&root_layout);
    screenStack.addScreen(screen_a);

    display.clear();
    screenStack.goTo(display, screen_a, gfx);
    display.flush();
}

void loop() {
    screenStack.renderApp(gfx);
    updateProg();
    display.flush();
}

int main() {
    window.create();
    window.loop(loop, setup);
}