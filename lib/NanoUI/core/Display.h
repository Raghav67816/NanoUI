#ifndef DISPLAY_H
#define DISPLAY_H

#include "Color.h"

class Display{
    public: 
        
    virtual void clear() = 0;
    virtual void flush() = 0;

    virtual void drawPixel(
        int x,
        int y,
        Color color
    ) = 0;

    virtual int getWidth();
    virtual int getHeight();
};

#endif
