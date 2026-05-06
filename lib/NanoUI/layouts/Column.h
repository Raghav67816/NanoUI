#include "Layout.h"


class Column: public Layout{

    private:
    int spacing = 4;

    public:
    Column(int x, int y, int w, int h): Layout(spacing, 10 + spacing, w, h){}

    void measureGeo(Graphics &gfx) override;
    void layout(Graphics &gfx) override;
};
