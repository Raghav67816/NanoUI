#include <vector>

class Widget{
    public:

    int x;
    int y;

    int w;
    int h;

    bool visible;
    bool enabled;

    std::vector<Widget*> children;
    Widget *parent = nullptr;

    virtual void draw() = 0;
    virtual void onEvent(int event) = 0;
    virtual void addChild(Widget *child) = 0;
};