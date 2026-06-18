#include "ListWidget.h"

void ListWidget::bindEvent(EventType event, std::function<void(ListItem *item)> callback){
    if(event == CURRENT_ITEM_CHANGED && callback != NULL){
        _onCurrentItemChanged = callback;
    }
}

void ListWidget::onCurrentItemChanged(){
    _onCurrentItemChanged(this->activeItem);
}

void ListWidget::addItem(ListItem *item){
    this->addChild(item);
    this->isDirty = true;
}

void ListWidget::removeItem(ListItem *item){
    this->removeChild(item);
    this->isDirty = true;
}

void ListWidget::draw(Graphics &gfx, int offsetX, int offsetY){

    // if(!gfx.boundCheck(this->x, this->x + this->w, this->h, this->y + this->h)) return;

    for(Widget *child: children){
        child->draw(gfx);
    }
}

void ListWidget::measureGeo(Graphics &gfx){
    if(this->w > parent->w){
        this->w = parent->w;
    }

    if(this->h > parent->h){
        this->h = parent->h;
    }
}
