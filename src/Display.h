#pragma once

#include <cstdint>

class Display{
    public: 
        
    virtual void clear() = 0;
    virtual void flush() = 0;

    virtual void drawPixel(
        int x,
        int y,
        uint16_t color
    ) = 0;

    virtual int getWidth();
    virtual int getHeight();
};
