#pragma once

#include "core/Color.h"
#include "widgets/Label.h"

class ListItem: public Label{

    private:
    bool isFocused = false;

    Color white = {0, 255, 255};

    public:
    ListItem(char* text): Label(20, 10, text, white){}

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
};
