#include "Widget.h"

void Widget::addChild(Widget *child){
    for(Widget *_child: children){
        if(_child == child || this == child){
            return;
        }   
    }

    if(child->parent != nullptr){
        child->parent->removeChild(child);
    }

    children.push_back(child);
    child->parent = this;
}

void Widget::removeChild(Widget *child){
    for(int i=0; i<children.size(); i++){
        if(children.at(i) == child){
            children[i] = children.back();
            children.pop_back();

            child->parent = nullptr;
            return;
        }
    }
}

void Widget::invalidate(){
    isDirty = true;
    Widget *currentWidget = parent;

    while(currentWidget != nullptr){
        currentWidget->isDirty = true;
        currentWidget = currentWidget->parent;
    }
}

void Widget::onEvent(EventType event){}

void Widget::bindEvent(EventType event, std::function<void()> callback){}
