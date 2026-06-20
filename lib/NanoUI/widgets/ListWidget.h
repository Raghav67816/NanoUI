#pragma once

#include "layouts/Column.h"
#include "widgets/ListItem.h"

class ListWidget: public Column{

    private:

    ListItem *activeItem = NULL;
    std::function<void(ListItem *item)> _onCurrentItemChanged;

    public:
    ListWidget(int x, int y, int w, int h): Column(x, y, w, h){}

    void bindEvent(EventType event, std::function<void(ListItem *item)> callback);
    // void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    // void measureGeo(Graphics &gfx) override;

    void addItem(ListItem *item);
    void removeItem(ListItem *item);

    void focusItem(int index);
    void onCurrentItemChanged();
};
