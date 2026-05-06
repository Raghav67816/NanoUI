#include "Layout.h"

class Column: public Layout{
    private:

    Widget &parent;
    int x, y, w, h;

    int spacing = 2;
    std::vector<Widget*> children = {};

    public:
    // Column(Widget &parent, int x, int y, int w, int h): parent(parent), x(x), y(y), w(w), h(h){}

    void layout() override;

    void removeChild(Widget *child) override;
};
