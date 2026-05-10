#include "ListWidget.h"

void ListWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    scrollWidget.draw(gfx, offsetX, offsetY);

    // gfx.fillRect(this->x, this->y, this->w, 54, Color {255, 255, 255});
}

void ListWidget::addItem(ListItem *item){
    for(ListItem* _item: items){
        if(_item == item){
            return;
        }
    }
    items.push_back(item);
}
