#include "ListWidget.h"
#include <iostream>

using namespace std;

void ListWidget::measureGeo(Graphics &gfx){
    if(this->w > this->parent->w){
        this->w = this->parent->w;
    }
    if(this->h > this->parent->h){
        this->h = this->parent->h;
    }
}

void ListWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    int drawX = this->x - this->offsetX;
    int drawY = this->y - this->offsetY;

    if(!gfx.boundCheck(drawX, drawX + this->w, drawY, drawY + this->h)) return;
    gfx.drawRect(drawX, drawY, this->w, this->h, {255, 255, 255});
}

void ListWidget::popOffset(int offsetX, int offsetY){
    this->offsetX -= offsetX;
    this->offsetY -= offsetY;
    
    this->isDirty = true;
}

void ListWidget::pushOffset(int offsetX, int offsetY){
    this->offsetX += offsetX;
    this->offsetY += offsetY;

    this->isDirty = true;
}

void ListWidget::bindEvent(EventType event, std::function<void()> callback){
    if(event == CURRENT_ITEM_CHANGED && callback != NULL){
        
    }
}
