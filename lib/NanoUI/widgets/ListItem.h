#pragma once

#include "core/Color.h"
#include "core/Event.h"
#include "widgets/Label.h"

#include "core/types.h"

#define INNER_PADDING 2

class ListItem: public Label{

    private:
    bool isFocused = false;
    const char* _text;

    Event<const char*> onSelect;
    
    Color white = {255, 255, 255};
    Color black = {0, 0, 0};


    public:
    ListItem(const char* text): Label(20, 10, text){
        Color white = {255, 255, 255};
        Label::setColor(white);
        text = _text;
    }

    void draw(Graphics &gfx, Theme& theme, int offsetX = 0, int offsetY = 0) override;
    void setFocused(bool isFocused);
    void processInput(InputTypes inputType, Cordinates point) override;
};
