#pragma once

#include "Color.h"
#include "Widget.h"

class Button: public Widget{

    private:
    std::function<void()> _onPress;

    public:
    int x, y;
    int w, h;
    char* labelText;

    Color bgColor;
    Color textColor;

    Button(int x, int y, int w, int h, char* labelText, Color bgColor, Color textColor){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->labelText = labelText;
        this->bgColor = bgColor;
        this->textColor = textColor;
    }

    void draw(Graphics &gfx) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void addChild(Widget *widget) override;

    void setText(Graphics &gfx, char *text);
    char* text();
};
