#include "ScrollWidget.h"
#include <iostream>

using namespace std;

void ScrollWidget::measureGeo(Graphics &gfx){
    if(this->w > this->parent->w) this->w = this->parent->w;
    if(this->h > this->parent->h) this->h = this->parent->h;
}

void ScrollWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    if(!gfx.boundCheck(drawX, drawX + this->w, drawY, drawY + this->h)) return;
    gfx.drawRect(drawX, drawY, this->w, this->h, {255, 255, 255});
}
