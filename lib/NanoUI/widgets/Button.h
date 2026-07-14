#pragma once

#include "core/Widget.h"
#include "core/Color.h"
#include "core/Event.h"

#include "core/types.h"

class Button: public Widget{

    private:
    Event<> onPress;

    public:
    char* labelText;

    Color bgColor;
    Color textColor;
    
    Button(int w, int h, char* labelText, Color bgColor, Color textColor): Widget(0, 0, w, h){
        this->w = w;
        this->h = h;
        this->labelText = labelText;
        this->bgColor = bgColor;
        this->textColor = textColor;
    }
    
    void draw(Graphics &gfx, Theme* theme, int offsetX = 0, int offsetY = 0) override;
    void measureGeo(Graphics &gfx) override;

    void processInput(InputTypes inputType, Cordinates point) override;

    void setText(Graphics &gfx, char *text);
    char* text();
};
