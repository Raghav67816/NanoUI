#include "Widget.h"
#include "Graphics.h"
#include "Display.h"

class Screen: public Widget{

    private:
    Display *display;
    Graphics *gfx;

    public:

    const char* title;

    Screen(Display *display, Graphics *gfx): display(display), gfx(gfx){}

    void draw() override;
    void onEvent(int eventType) override;
    void addChild(Widget *child) override;

    void setTitle(const char* title, Color color);
};
