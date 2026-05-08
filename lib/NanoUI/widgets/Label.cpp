#include "Label.h"

void Label::draw(Graphics &gfx){
    gfx.drawText(x, y, labelText, color);
}

void Label::measureGeo(Graphics &gfx){
    this->w = gfx.getTextWidth(labelText);
    h = 10;
}

void Label::setText(char* _text){
    labelText = _text;
    isDirty = true;
}

void Label::setColor(Color color){
}

char* Label::text(){
    return labelText;
}

void Label::bindEvent(EventType event, std::function<void()> callback){}

void Label::onEvent(EventType event){}