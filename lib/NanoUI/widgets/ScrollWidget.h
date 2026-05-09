#include "core/Widget.h"

class ScrollWidget: public Widget{

    private:
    int viewportX = 0;
    int viewportY = 0;

    public:
    int w, h;

    ScrollWidget(int x, int y, int w, int h): Widget(0, 0, w, h){}

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    void measureGeo(Graphics &gfx) override;

    void pushOffset(int offsetX, int offsetY);
    void popOffset(int offsetX, int offsetY);
};
