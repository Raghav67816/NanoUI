#pragma once

#include <vector>
#include <functional>
#include "Graphics.h"

enum EventType{
    BUTTON_PRESSED,
    BUTTON_RELEASED,
};


class Widget{
    public:

    int x;
    int y;

    int w;
    int h;

    bool visible;
    bool enabled;

    std::vector<Widget*> children;
    Widget *parent = nullptr;

    virtual void draw(Graphics &gfx) = 0;
    virtual void onEvent(EventType event) = 0;
    virtual void bindEvent(EventType event, std::function<void()> callback) = 0;
    virtual void addChild(Widget *child) = 0;
    virtual void removeChild(Widget *child) = 0;
};