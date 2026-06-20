#include "ListItem.h"

void ListItem::draw(Graphics &gfx, int offsetX, int offsetY){
    Label::draw(gfx);
    if(this->isFocused){
        setColor(black);
        gfx.fillRect(this->x, this->y, this->w, this->h + 2, white);
    }
}

void ListItem::setFocused(bool isFocused){
    this->isFocused = isFocused;
}
