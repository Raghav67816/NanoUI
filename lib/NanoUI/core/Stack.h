#pragma once

#include <vector>

#include "core/Event.h"
#include "widgets/Screen.h"

class Stack{
    private:
    int screenIndex = 0;

    Screen* activeScreen = nullptr;
    std::vector<Screen*> screens = {};

    Graphics &gfx;
    Display &display;

    void onCurrentScreenChanged(Display &display, Graphics &gfx);

    public:

    Event<Screen*> onScreenChanged;

    Stack(Display &display, Graphics &gfx):display(display), gfx(gfx){}

    void addScreen(Screen &screen);
    void removeScreen(Screen &screen);

    void forward();
    void back();

    void goTo(Display &display, Screen &screen, Graphics &gfx);
    Screen* getActiveScreen();

    void renderApp(Graphics &gfx);
};
