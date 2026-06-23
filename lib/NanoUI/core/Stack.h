#pragma once

#include <vector>

#include "Theme.h"
#include "core/Event.h"
#include "widgets/Screen.h"

class Stack{
    private:
    int screenIndex = 0;

    Screen* activeScreen = nullptr;
    std::vector<Screen*> screens = {};

    Graphics &gfx;
    Display &display;
    Theme* _theme;

    void onCurrentScreenChanged(Display &display, Graphics &gfx);

    public:

    Event<Screen*> onScreenChanged;

    Stack(Display &display, Graphics &gfx, Theme* theme):display(display), gfx(gfx), _theme(theme){}

    void addScreen(Screen &screen);
    void removeScreen(Screen &screen);

    void forward();
    void back();

    void goTo(Display &display, Screen &screen, Graphics &gfx);
    Screen* getActiveScreen();

    void setTheme(Theme* theme);

    void renderApp(Graphics &gfx);
};
