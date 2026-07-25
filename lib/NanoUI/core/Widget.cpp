#include "Widget.h"
#include "widgets/Screen.h"

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
    child->setSizeMetrics(*this->size_metrics);
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

Region Widget::getBounds(){
    Region region = {this->x, this->y, this->w, this->h};
    return region;
}

void Widget::setSizeMetrics(SizeMetrics& size_metrics){
    this->size_metrics = &size_metrics;
}

Widget* Widget::getTopLevelParent(){
    Widget* current = this;
    while(current->parent != nullptr){
        current = current->parent;
    }

    return current;
}

void Widget::invalidate(Screen* screen, Widget* widget){
    screen->addDamagedWidget(widget);
}

void Widget::clear(Graphics& gfx, Color bgColor){
    Region r = this->getBounds();
    gfx.fillRect(r.x, r.y, r.w, r.h, bgColor);
}
