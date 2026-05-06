#include "Column.h"

// Should be below the title bar 
// i.e 

void Column::layout(){
    int currentY = y + spacing;

    for(Widget *child: children){
        child->x = x + spacing;
        child->y = currentY;


        currentY += child->h + spacing;
    }
}
