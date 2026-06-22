#include "ListWidget.h"
#include <Arduino.h>

void ListWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    Column::draw(gfx, 0, this->local_offsetY);
}

void ListWidget::bindEvent(EventType event, std::function<void(ListItem *item)> callback)
{
    if (event == CURRENT_ITEM_CHANGED && callback != NULL)
    {
        _onCurrentItemChanged = callback;
    }
}

void ListWidget::onCurrentItemChanged()
{
    _onCurrentItemChanged(this->getFocusedItem());
}

void ListWidget::focusItem(int index)
{
    this->clearFocus();

    if(index <= 0){
        index = 0;
    }

    if(index >= (int)this->children.size()){
        index = (int)this->children.size() - 1;
    }

    ListItem *item = static_cast<ListItem *>(this->children[index]);
    item->setFocused(true);
    this->currentFocusedIndex = index;

    this->local_offsetY = 10 * this->currentFocusedIndex;
}

ListItem* ListWidget::getFocusedItem()
{
    ListItem* item = static_cast<ListItem*>(children[this->currentFocusedIndex]);
    return item;
}

int ListWidget::getFocusedItemIndex(){
    return this->currentFocusedIndex;
}

void ListWidget::clearFocus(){
    for(Widget* child: this->children){
        ListItem *item = static_cast<ListItem*>(child);
        item->setFocused(false);
        item->setColor({255, 255, 255});
    }
}
