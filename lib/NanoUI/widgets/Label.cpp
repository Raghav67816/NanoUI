#include "Label.h"

void Label::draw(Graphics &gfx, int offsetX, int offsetY){
    int drawX = x - offsetX;
    int drawY = y - offsetY;

    gfx.drawText(
        drawX,
        drawY,
        labelText,
        color
    );
}

void Label::measureGeo(Graphics &gfx){
    this->w = gfx.getTextWidth(labelText);
    h = 10;
}

void Label::setText(char* _text){
    labelText = _text;
    invalidate();
}

void Label::setColor(Color _color){
    color = _color;
    invalidate();
}

char* Label::text(){
    return labelText;
}

void Label::bindEvent(EventType event, std::function<void()> callback){}
void Label::onEvent(EventType event){}