#pragma once

#include "Layout.h"

class Column: public Layout{

    public:
    Column(int x, int y, int w, int h): Layout(x + spacing, y + spacing, w, h){}

    void layout(Graphics &gfx) override;
};
