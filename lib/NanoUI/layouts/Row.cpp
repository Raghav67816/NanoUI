#include "Row.h"

void Row::layout(Graphics &gfx){
    int currentX = x + spacing;
    for(Widget *child: children){
        child->x = currentX;
        child->y = y + spacing;

        currentX += child->w + spacing + contentSpacing;
    }
}
