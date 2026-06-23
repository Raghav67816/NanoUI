#pragma once

#include "core/Color.h"
#include "core/Widget.h"
#include "core/Graphics.h"

class Label: public Widget{
    private:

    public:
    const char* labelText;
    Color color;


    Label(int w, int h, const char* text, Color color): Widget(0, 0, w, h), labelText(text), color(color){}

    void draw(Graphics &gfx, Theme* theme, int offsetX = 0, int offsetY = 0) override;
    void measureGeo(Graphics &gfx) override;

    void setText(char* text);
    void setColor(Color color);

    const char* text();
};