#pragma once

#include "core/Widget.h"
#include "widgets/Label.h"

class ListItem: public Widget{

    private:
    Label *label;
    bool isFocused = false;

    public:
    ListItem(char* text){
        label = &Label(20, 10, text, {255, 255, 255});
    }
};
