#include "Layout.h"

void Layout::draw(Graphics &gfx){
    for(Widget *child: children){
        child->measureGeo(gfx);
    }

    layout(gfx);

    for(Widget *child: children){
        child->draw(gfx);
    }
}

void Layout::measureGeo(Graphics &gfx){}

void Layout::onEvent(EventType event){}
void Layout::bindEvent(EventType event, std::function<void()> callback){}