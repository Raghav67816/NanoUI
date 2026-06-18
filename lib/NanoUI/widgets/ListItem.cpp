#include "ListItem.h"

void ListItem::draw(Graphics &gfx, int offsetX, int offsetY){
    for(Widget *item: children){
        item->draw(gfx);
    }
}
