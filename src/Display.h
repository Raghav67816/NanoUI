#pragma once

class Display{
    public: 
        
    virtual void clear() = 0;
    virtual void flush() = 0;

    virtual void drawPixel(
        int x,
        int y,
        bool color
    ) = 0;

    virtual int getWidth();
    virtual int getHeight();
};
