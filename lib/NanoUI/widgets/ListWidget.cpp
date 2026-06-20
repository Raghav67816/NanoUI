#include "ListWidget.h"

void ListWidget::bindEvent(EventType event, std::function<void(ListItem *item)> callback){
    if(event == CURRENT_ITEM_CHANGED && callback != NULL){
        _onCurrentItemChanged = callback;
    }
}

void ListWidget::onCurrentItemChanged(){
    _onCurrentItemChanged(this->activeItem);
}

void ListWidget::addItem(ListItem *item){
    this->addChild(item);
    this->isDirty = true;
}

void ListWidget::removeItem(ListItem *item){
    this->removeChild(item);
    this->isDirty = true;
}

void ListWidget::focusItem(int index){
    if(index > this->children.capacity()) return;
    ListItem *item = static_cast<ListItem*>(this->children[index]);
    item->setFocused(true);
    this->currentFocusedIndex = index;
}

int ListWidget::getFocusedItem(){
    return this->currentFocusedIndex;
}
