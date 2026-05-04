#include "Widget.h"
#include "Graphics.h"
#include "Display.h"

class Screen: public Widget{

    private:
    Display *display;

    public:

    const char* title;

    Screen(Display *display): display(display){}

    void draw(Graphics &gfx);
    void onEvent(int eventType) override;
    void addChild(Widget *child) override;

    void setTitle(Graphics *gfx, const char* title, Color color);
};
