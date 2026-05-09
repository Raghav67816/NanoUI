#include "Layout.h"

void Layout::draw(Graphics &gfx, int offsetX, int offsetY){
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
