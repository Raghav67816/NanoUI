#include "ScrollWidget.h"

void ScrollWidget::measureGeo(Graphics &gfx){
    
}

void ScrollWidget::draw(Graphics &gfx, int offsetX, int offsetY){
    int drawX = offsetX + viewportX;
    int drawY = offsetY + viewportY;

    Color white = {255, 255, 255};

    gfx.drawRect(this->x, this->y, this->w, this->h, white);

    for(Widget *child: children){
        child->draw(gfx, drawX, drawY);
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
