#pragma once

#include <vector>
#include <functional>
#include "Graphics.h"

enum EventType
{
    BUTTON_PRESSED,
    BUTTON_RELEASED,
};

class Widget
{
public:
    int x;
    int y;

    int w;
    int h;

    bool visible;
    bool enabled;

    std::vector<Widget *> children;
    Widget *parent = nullptr;

    Widget(int x = 0, int y = 0, int w = 0, int h = 0)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    virtual void draw(Graphics &gfx) = 0;
    virtual void onEvent(EventType event) = 0;
    virtual void bindEvent(EventType event, std::function<void()> callback) = 0;
    virtual void addChild(Widget *child) = 0;
    virtual void removeChild(Widget *child) = 0;
    virtual void measureGeo(Graphics &gfx) {};
};