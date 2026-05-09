#include "ScrollWidget.h"


void ScrollWidget::measureGeo(Graphics &gfx){
    if(this->parent != nullptr){
        this->x = this->parent->x;
        this->y = this->parent->y;

        this->w = this->parent->w;
        this->h = this->parent->h;
    }
}

void ScrollWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    for(Widget *child: children){
        child->draw(gfx, offsetX, offsetY);
    }
}

void ScrollWidget::pushOffset(int offsetX, int offsetY){
    viewportX += offsetX;
    viewportY += offsetY;

    invalidate();
}

void ScrollWidget::popOffset(int offsetX, int offsetY){
    viewportX -= offsetX;
    viewportY -= offsetY;

    invalidate();
}
