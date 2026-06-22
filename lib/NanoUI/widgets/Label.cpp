#include "Label.h"
#include <Arduino.h>

void Label::draw(Graphics &gfx, int offsetX, int offsetY){

    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

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

const char* Label::text(){
    return labelText;
}
