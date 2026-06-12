#include "ScrollWidget.h"
#include <iostream>

using namespace std;

void ScrollWidget::measureGeo(Graphics &gfx){
    
}

void ScrollWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    cout << this->w << endl;

    if(!gfx.boundCheck(drawX, drawX + this->w, drawY, drawY + this->h)) return;
    gfx.drawRect(drawX, drawY, this->w, this->h, {255, 255, 255});
}
