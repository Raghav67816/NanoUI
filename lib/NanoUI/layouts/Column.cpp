#include "Column.h"

void Column::layout(Graphics &gfx){
    int currentY = this->y + spacing;
    for(Widget *child: children){
        child->x = this->x + spacing;
        child->y = currentY;

        currentY += child->h + spacing;
    }
}

