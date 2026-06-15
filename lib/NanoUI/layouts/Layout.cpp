#include "Layout.h"
#include <iostream>

void Layout::draw(Graphics &gfx, int offsetX, int offsetY){

    for(Widget *child: children){
        child->w -= this->spacing;
        child->h -= this->spacing;
        child->measureGeo(gfx);
    }

    layout(gfx);

    for(Widget *child: children){
        child->draw(gfx, offsetX, offsetY);
    }

}

void Layout::setSpacing(int _spacing){
    spacing = _spacing;
}

void Layout::measureGeo(Graphics &gfx){}
