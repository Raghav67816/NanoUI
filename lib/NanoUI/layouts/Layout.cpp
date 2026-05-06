#include "Layout.h"

void Layout::addChild(Widget *widget){
    children.push_back(widget);
}

void Layout::removeChild(Widget *widget){
    int index = 0;
    for(int i=0; i < children.size(); i++){
        if(children.at(i) == widget){
            children[i] = children.back();
            children.pop_back();
            return;
        }
    }
}

void Layout::draw(Graphics &gfx){
    layout();
    for(Widget *child: children){
        child->draw(gfx);
    }
}

void Layout::onEvent(EventType event){}
void Layout::bindEvent(EventType event, std::function<void()> callback){}
