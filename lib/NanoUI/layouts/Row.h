#include "Layout.h"

class Row: public Layout{
    private:
    int spacing = 10;

    public:
    Row(int x, int y, int w, int h): Layout(spacing, 10 + spacing, w, h){}

    void layout(Graphics &gfx) override;
};
