#pragma once

#include "core/Color.h"
#include "widgets/Label.h"

class ListItem: public Label{

    private:
    bool isFocused = false;
    
    Color white = {255, 255, 255};
    Color black = {0, 0, 0};

    // void removeFocus();

    public:
    ListItem(char* text): Label(20, 10, text, {0, 0, 0}){
        Color white = {255, 255, 255};
        Label::setColor(white);
    }

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;

    void setFocused(bool isFocused);
};
