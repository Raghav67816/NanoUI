#include "ListWidget.h"

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
    if (index >= this->children.size())
        return;
    ListItem *item = static_cast<ListItem *>(this->children[index]);
    item->setFocused(true);
    this->currentFocusedIndex = index;
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
