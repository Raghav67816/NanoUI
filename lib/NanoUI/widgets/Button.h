#pragma once

#include "../core/Widget.h"
#include "core/Color.h"

class Button: public Widget{

    private:
    std::function<void()> _onPress;

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
    
    void draw(Graphics &gfx) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void measureGeo(Graphics &gfx) override;

    void setText(Graphics &gfx, char *text);
    char* text();
};
