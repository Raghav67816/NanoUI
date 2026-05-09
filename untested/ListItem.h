#pragma once

#include "Label.h"

class ListItem: public Label {
    private:
    bool isSelected = false;
    std::function<void(char itemText)> _onItemPressed;

    public:
    ListItem(int w, int h, char* itemText, Color textColor):
    Label(w, h, labelText, textColor){}

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
};
