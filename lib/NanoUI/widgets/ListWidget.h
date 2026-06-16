#include <cstdio>

#include "core/Widget.h"
#include "layouts/Column.h"

class ListWidget: public Widget{

    private:
    int offsetX = 0;
    int offsetY = 0;

    int focusedItem = 0;

    Column *col = nullptr;


public:
    ListWidget(int x, int y, int w, int h): Widget(x, y, w, h) {
        Column _col(x, y, w, h);
        this->col = col;
    }

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    void measureGeo(Graphics &gfx) override;

    void pushOffset(int offsetX, int offsetY);
    void popOffset(int offsetX, int offsetY);

    void focusItem(int itemIndex);

    void bindEvent(EventType event, std::function<void()> callback) override;
};
