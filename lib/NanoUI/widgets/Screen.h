#pragma once

#include <functional>

#include "core/Widget.h"

class Screen: public Widget {
    private:
    Display *display;

    public:

    const char* title;

    Screen(Display *display, const char* title): Widget(0, 0, display->getWidth(), display->getHeight()){
        this->display = display;
        this->title = title;
    }

    void draw(Graphics &gfx, Theme*  theme, int offsetX = 0, int offsetY = 0) override;
    void setTitle(Graphics *gfx, const char* title, Color color);
    void processInput(InputTypes inputType, Cordinates points) override;
    bool _dirtyCheck();
};

