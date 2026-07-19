#pragma once

#include "Display.h"
#include "types.h"

class Graphics{
    private:
    Display *display;
    SizeMetrics *_size_metrics;

    void drawChar(int x, int y, char c, Color color);
    
    
    public:
    Graphics(Display *display, SizeMetrics* size_metrics): display(display), _size_metrics(size_metrics){}
    
    bool boundCheck(int x1, int x2, int y1, int y2);
    
    void drawLine(int x1, int x2, int y1, int y2, Color color);
    void drawRect(int x, int y, int w, int h, Color color);
    void drawCircle(int x, int y, int radius, Color color);

    void fillRect(int x, int y, int w, int h, Color color);
    void fillCircle(int x, int y, int radius, Color color);
    
    void drawText(int x, int y, const char* text, Color color);
    int getTextWidth(const char* text);
};