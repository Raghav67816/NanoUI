#pragma once

#include "core/Widget.h"
#include "ListItem.h"

#include "ScrollWidget.h"
#include "layouts/Column.h"

class ListWidget: public Widget{
    private:
    Column layout;
    ScrollWidget scrollWidget;

    std::vector<ListItem*> items;

    public:
    ListWidget(int w, int h): 
    Widget(0, 0, w, h),
    scrollWidget(0, 0, w, h),
    layout(0, 0, w, h){
        scrollWidget.parent = this;
        scrollWidget.h = h;
        scrollWidget.w = w;

        scrollWidget.addChild(&layout);
    }

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    void addItem(ListItem *item);
    void removeItem(ListItem *item);
};
