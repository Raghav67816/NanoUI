#include "Label.h"
#include "Screen.h"

#include <Arduino.h>

void Label::draw(Graphics &gfx, Theme& theme, int offsetX, int offsetY){

    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    if(this->parent != nullptr){
        this->bgColor = this->parent->bgColor;
    }

    Color textColor = {0, 0, 0};
    if(this->hasCustomColor){
        textColor = color;
    }

    else{
        textColor = theme.foreground;
    }

    gfx.drawText(
        drawX,
        drawY,
        labelText,
        textColor
    );
}

void Label::measureGeo(Graphics &gfx){
    this->w = gfx.getTextWidth(labelText);
    this->h = gfx.getTextHeight();
}

void Label::setText(char* _text){
    labelText = _text;
    Widget* tParent = this->getTopLevelParent();
    Screen* tScreen = static_cast<Screen*>(tParent);
    this->invalidate(tScreen, this);
}

void Label::setColor(Color _color){
    color = _color;
    hasCustomColor = true;
}

const char* Label::text(){
    return labelText;
}

void Label::processInput(InputTypes inputType, Cordinates points){}

