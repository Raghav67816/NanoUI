#pragma once

#include <functional>
#include "core/Widget.h"

class Screen: public Widget {

    protected:
    bool needsUpdate = false;

    private:
    Display *display;

    public:

    const char* title;

    Screen(Display *display, const char* title): Widget(0, 0, display->getWidth(), display->getHeight()){
        this->display = display;
        this->title = title;
    }

    void draw(Graphics &gfx) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;

    void setTitle(Graphics *gfx, const char* title, Color color);

    bool requireUpdate();
    void regionCheck();
};

