#include "Layout.h"

void Layout::draw(Graphics &gfx, Theme& theme, int offsetX, int offsetY){

    for(Widget *child: children){
        child->measureGeo(gfx);
    }

    layout(gfx);

    for(Widget *child: children){
        child->draw(gfx, theme, offsetX, offsetY);
    }

}

void Layout::setSpacing(int _spacing){
    spacing = _spacing;
}

void Layout::setContentSpacing(int spacing){
    this->contentSpacing = spacing;
}


void Layout::measureGeo(Graphics &gfx){}
void Layout::processInput(InputTypes inputType, Cordinates points){}
