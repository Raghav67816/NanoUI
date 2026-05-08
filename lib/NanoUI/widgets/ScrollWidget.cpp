#include "ScrollWidget.h"
#include "Arduino.h"

void ScrollWidget::draw(Graphics &gfx){

    int currentY = y;

    Serial.println("WHEN DRAWING");
    for(Widget *child: children){
        child->measureGeo(gfx);


        child->x = x + 2;
        child->y = currentY;
        currentY += child->h + 2;
    }

    for(Widget *child: children){
        child->draw(gfx);
    }
}

void ScrollWidget::scroll(int _offsetX, int _offsetY){
    offsetX += _offsetX;
    offsetY += _offsetY;

    for(Widget *child: children){
        child->isDirty = true;
    }
}

void ScrollWidget::addChild(Widget *child){
    children.push_back(child);
    child->parent = this;
}


void ScrollWidget::removeChild(Widget *child){}
void ScrollWidget::bindEvent(EventType event, std::function<void()> callback){}
void ScrollWidget::onEvent(EventType event){}
