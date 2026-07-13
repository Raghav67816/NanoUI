#pragma once

#include "Display.h"
#include <LovyanGFX.h>

class TFTDisplay: public Display{

    private:
    const int w;
    const int h;

    LGFX_Device *display;

    public:
    TFTDisplay(int w, int h, LGFX_Device *_display): w(w), h(h), display(_display){}

    void clear() override;
    void flush() override;

    void drawPixel(int x, int y, Color color) override;

    int getHeight() override;
    int getWidth() override;
};

