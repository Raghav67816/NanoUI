#pragma once

#include "core/Widget.h"

class Layout: public Widget{
    public:

    int spacing = 4;
    Layout(int x, int y, int w, int h):
    Widget(x, y, w, h){}

    virtual void layout(Graphics &gfx) = 0;
    
    void setSpacing(int spacing);

    void draw(Graphics &gfx, Theme* theme, int offsetX = 0, int offsetY = 0);
    void measureGeo(Graphics &gfx) override;
};
