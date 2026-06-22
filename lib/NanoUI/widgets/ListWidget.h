#pragma once

#include "layouts/Column.h"
#include "widgets/ListItem.h"

class ListWidget: public Column{

    private:

    std::function<void(ListItem *item)> _onCurrentItemChanged;

    int currentFocusedIndex = 0;

    public:
    int local_offsetY = 0;
    
    ListWidget(int x, int y, int w, int h): Column(x, y, w, h){}

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    void bindEvent(EventType event, std::function<void(ListItem *item)> callback);

    ListItem* getFocusedItem();
    int getFocusedItemIndex();

    void clearFocus();
    void focusItem(int index);

    void onCurrentItemChanged();
};
