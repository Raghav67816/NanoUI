#include "core/Widget.h"

#define LAYOUT_PADDING 2
#define TITLE_BAR_HEIGHT 10

class Layout: public Widget{
    private:

    int spacing = 2;

    int x, y, w, h;

    std::vector<Widget*> children = {};

    public:
    Layout(int x, int y, int w, int h): x(x), y(y), w(w), h(h){}

    void draw(Graphics &gfx) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void addChild(Widget *child) override;
    void removeChild(Widget *child) override;

    virtual void layout() = 0;
};