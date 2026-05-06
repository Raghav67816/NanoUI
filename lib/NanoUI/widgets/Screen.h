#pragma once


#include <functional>
#include "../core/Widget.h"



class Screen: public Widget {

    private:
    Display *display;

    public:

    const char* title;

    Screen(Display *display, const char* title): display(display), title(title){}

    void draw(Graphics &gfx);
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void addChild(Widget *child) override;
    void removeChild(Widget *child) override;

    void setTitle(Graphics *gfx, const char* title, Color color);
};

