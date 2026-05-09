#pragma once

#include "core/Widget.h"

#define OUTER_PADDING 2;
#define INNER_PADDING 2;

class Layout: public Widget{
    public:

    int spacing = 4;
    Layout(int x, int y, int w, int h):
    Widget(x, y, w, h){}

    virtual void layout(Graphics &gfx) = 0;
    
    void setSpacing(int spacing);

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0);
    void measureGeo(Graphics &gfx) override;

    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
};
