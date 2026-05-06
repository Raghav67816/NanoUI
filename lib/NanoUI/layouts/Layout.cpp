#include "Layout.h"

void Layout::addChild(Widget* child){
    children.push_back(child);
    child->parent = this;
}

void Layout::removeChild(Widget *child){
    for(int i=0; i<children.size(); i++){
        if(children.at(i) == child){
            children[i] = children.back();
            children.pop_back();

            child->parent = nullptr;
            return;
        }
    }
}

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