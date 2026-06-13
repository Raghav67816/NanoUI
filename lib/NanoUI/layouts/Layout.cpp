#include "Layout.h"
#include <iostream>

void Layout::draw(Graphics &gfx, int offsetX, int offsetY){

    int totalSpacing = OUTER_PADDING + INNER_PADDING;

    for(Widget *child: children){
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
