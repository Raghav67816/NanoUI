#include "Label.h"

void Label::draw(Graphics &gfx){
    gfx.drawText(x, y, labelText, color);
}

void Label::setText(char *_text){

}

void Label::setColor(Color color){

}

char* Label::text(){
    return labelText;
}

void bindEvent(EventType event, std::function<void()> callback){}

void onEvent(EventType event){}
void Label::addChild(Widget *child){}
void Label::removeChild(Widget *child){}
