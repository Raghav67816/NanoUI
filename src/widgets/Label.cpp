#include "Label.h"
#include "Graphics.h"

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

void Label::onEvent(int event){}
void Label::addChild(Widget *child){}
