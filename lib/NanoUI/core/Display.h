#ifndef DISPLAY_H
#define DISPLAY_H

#include "Color.h"

class Display{
    public: 

    virtual ~Display() = default;
        
    virtual void clear() = 0;
    virtual void flush() = 0;

    virtual void drawPixel(
        int x,
        int y,
        Color color
    ) = 0;

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};

#endif
