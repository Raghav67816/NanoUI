#pragma once

#include <vector>

#include "Theme.h"

#include "core/types.h"
#include "core/Event.h"

#include "widgets/Screen.h"

class App{
    private:
    int screenIndex = 0;

    Screen* activeScreen = nullptr;
    std::vector<Screen*> screens = {};

    Graphics &gfx;
    Display &display;
    Theme _theme;
    SizeMetrics size_metrics;

    void repaintDamaged();
    void onCurrentScreenChanged(Display &display, Graphics &gfx);

    public:

    Event<Screen*> onScreenChanged;

    App(Display &display, Graphics &gfx, Theme& theme, SizeMetrics& size_metrics_):display(display), gfx(gfx), _theme(theme), size_metrics(size_metrics_){}

    void addScreen(Screen &screen);
    void removeScreen(Screen &screen);

    void forward();
    void back();

    void goTo(Display &display, Screen &screen, Graphics &gfx);
    Screen* getActiveScreen();

    void setTheme(Theme& theme);
    void setSizes(SizeMetrics& size_metrics);

    void renderApp(Graphics &gfx);
};
