#pragma once

#include "Display.h"
#include <stdio.h>

struct Font{
    uint8_t width;
    uint8_t height;
    uint16_t *data;
};

class Graphics{
    private:
    Display *display;
    void drawChar(int x, int y, char c); 

    

    public:
    Graphics(Display *display): display(display){}
    
    bool boundCheck(int x1, int x2, int y1, int y2);
    
    void drawLine(int x1, int x2, int y1, int y2);
    void drawRect(int start, int h, int w);
    void fillRect(int x, int y, int w, int h, uint16_t color);

    void drawText(int x, int y, const char* text);
};