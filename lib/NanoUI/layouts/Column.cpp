#include "Column.h"
#include "Arduino.h"

void Column::layout(Graphics &gfx){
    int currentY = y + spacing;
    for(Widget *child: children){
        child->x = x + spacing;
        child->y = currentY;

        currentY += child->h + spacing;
    }
}

