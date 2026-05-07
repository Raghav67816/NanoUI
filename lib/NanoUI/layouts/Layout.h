#pragma once

#include "core/Widget.h"

#define OUTER_PADDING 2;
#define INNER_PADDING 2;

class Layout: public Widget{
    public:
    Layout(int x, int y, int w, int h):
    Widget(x, y, w, h){}

    virtual void layout(Graphics &gfx) = 0;

    void draw(Graphics &gfx);

    void addChild(Widget *widget) override;
    void removeChild(Widget *widget) override;

    void measureGeo(Graphics &gfx) override;

    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
};
