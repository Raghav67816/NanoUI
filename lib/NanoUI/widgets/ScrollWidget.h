/*

Scroll Widget

Scroll widgets manages it's own local view port
increase offset 

if child's x and y exists in the viewport it is drawn

*/

#include "core/Widget.h"


class ScrollWidget: public Widget{
    private:
    int offsetX = 0;
    int offsetY = 0;

    public:
    ScrollWidget(int w, int h): Widget(0, 0, w, h){}

    void draw(Graphics &gfx) override;
    void scroll(int offsetX, int offsetY);

    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void addChild(Widget *child) override;
    void removeChild(Widget *child) override;
};
