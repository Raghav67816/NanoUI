#pragma once

#include "Display.h"

class Graphics{
    private:
    Display *display;
    void drawChar(int x, int y, char c, int charSize, Color color);
    
    
    
    public:
    Graphics(Display *display): display(display){}
    
    bool boundCheck(int x1, int x2, int y1, int y2);
    
    void drawLine(int x1, int x2, int y1, int y2, Color color);
    void drawRect(int x, int y, int w, int h, Color color);
    void drawCircle(int x, int y, int radius, Color color);

    void fillRect(int x, int y, int w, int h, Color color);
    void fillCircle(int x, int y, int radius, Color color);
    
    void drawText(int x, int y, const char* text, int fontSize, Color color);
    int getTextWidth(const char* text);
};