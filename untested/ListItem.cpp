#include "ListItem.h"

void ListItem::draw(Graphics &gfx, int offsetX, int offsetY){
    Color white = {255, 255, 255};
    if(isSelected){
        gfx.fillRect(
            this->x - offsetX,
            this->y - offsetY,
            this->w,
            this->h,
            white
        );
    }

    Label::draw(gfx, offsetX, offsetY);
}
