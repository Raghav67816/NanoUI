#include "Row.h"

void Row::measureGeo(Graphics &gfx){}

void Row::layout(Graphics &gfx){
    int currentX = x + spacing;
    for(Widget *child: children){
        child->x = currentX;
        child->y = y + spacing;

        currentX += child->w + spacing;
    }
}
