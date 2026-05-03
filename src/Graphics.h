#pragma once

#include "Display.h"
#include <stdio.h>

class Graphics{
    private:
    Display *display;

    public:
    Graphics(Display *display): display(display){}

    bool boundCheck(int x1, int x2, int y1, int y2);

    void drawLine(int x1, int x2, int y1, int y2);
    void drawRect(int start, int h, int w);
    void fillRect(int x, int y, int w, int h, uint16_t color);
};